import argparse
import copy


def generate_neighbours(path):

    dict_of_neighbours = {}

    with open(path) as f:
        for line in f:
            if line.split()[0] not in dict_of_neighbours:
                _list = []
                _list.append([line.split()[1], line.split()[2]])
                dict_of_neighbours[line.split()[0]] = _list
            else:
                dict_of_neighbours[line.split()[0]].append(
                    [line.split()[1], line.split()[2]]
                )
            if line.split()[1] not in dict_of_neighbours:
                _list = []
                _list.append([line.split()[0], line.split()[2]])
                dict_of_neighbours[line.split()[1]] = _list
            else:
                dict_of_neighbours[line.split()[1]].append(
                    [line.split()[0], line.split()[2]]
                )

    return dict_of_neighbours


def generate_first_solution(path, dict_of_neighbours):
    with open(path) as f:
        start_node = f.read(1)
    end_node = start_node

    first_solution = []

    visiting = start_node

    distance_of_first_solution = 0
    while visiting not in first_solution:
        minim = 10000
        for k in dict_of_neighbours[visiting]:
            if int(k[1]) < int(minim) and k[0] not in first_solution:
                minim = k[1]
                best_node = k[0]

        first_solution.append(visiting)
        distance_of_first_solution = distance_of_first_solution + int(minim)
        visiting = best_node

    first_solution.append(end_node)

    position = 0
    for k in dict_of_neighbours[first_solution[-2]]:
        if k[0] == start_node:
            break
        position += 1

    distance_of_first_solution = (
        distance_of_first_solution
        + int(dict_of_neighbours[first_solution[-2]][position][1])
        - 10000
    )
    return first_solution, distance_of_first_solution


def find_neighborhood(solution, dict_of_neighbours):
    neighborhood_of_solution = []

    for n in solution[1:-1]:
        idx1 = solution.index(n)
        for kn in solution[1:-1]:
            idx2 = solution.index(kn)
            if n == kn:
                continue

            _tmp = copy.deepcopy(solution)
            _tmp[idx1] = kn
            _tmp[idx2] = n

            distance = 0

            for k in _tmp[:-1]:
                next_node = _tmp[_tmp.index(k) + 1]
                for i in dict_of_neighbours[k]:
                    if i[0] == next_node:
                        distance = distance + int(i[1])
            _tmp.append(distance)

            if _tmp not in neighborhood_of_solution:
                neighborhood_of_solution.append(_tmp)

    index_of_last_item_in_the_list = len(neighborhood_of_solution[0]) - 1

    neighborhood_of_solution.sort(key=lambda x: x[index_of_last_item_in_the_list])
    return neighborhood_of_solution


def tabu_search(
    first_solution, distance_of_first_solution, dict_of_neighbours, iters, size
):
    count = 1
    solution = first_solution
    tabu_list = []
    best_cost = distance_of_first_solution
    best_solution_ever = solution

    while count <= iters:
        neighborhood = find_neighborhood(solution, dict_of_neighbours)
        index_of_best_solution = 0
        best_solution = neighborhood[index_of_best_solution]
        best_cost_index = len(best_solution) - 1

        found = False
        while not found:
            i = 0
            while i < len(best_solution):
                if best_solution[i] != solution[i]:
                    first_exchange_node = best_solution[i]
                    second_exchange_node = solution[i]
                    break
                i = i + 1

            if [first_exchange_node, second_exchange_node] not in tabu_list and [
                second_exchange_node,
                first_exchange_node,
            ] not in tabu_list:
                tabu_list.append([first_exchange_node, second_exchange_node])
                found = True
                solution = best_solution[:-1]
                cost = neighborhood[index_of_best_solution][best_cost_index]
                if cost < best_cost:
                    best_cost = cost
                    best_solution_ever = solution
            else:
                index_of_best_solution = index_of_best_solution + 1
                best_solution = neighborhood[index_of_best_solution]

        if len(tabu_list) >= size:
            tabu_list.pop(0)

        count = count + 1

    return best_solution_ever, best_cost


def main(args=None):
    dict_of_neighbours = generate_neighbours(args.File)

    first_solution, distance_of_first_solution = generate_first_solution(
        args.File, dict_of_neighbours
    )

    best_sol, best_cost = tabu_search(
        first_solution,
        distance_of_first_solution,
        dict_of_neighbours,
        args.Iterations,
        args.Size,
    )

    print(f"Best solution: {best_sol}, with total distance: {best_cost}.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Tabu Search")
    parser.add_argument(
        "-f",
        "--File",
        type=str,
        help="Path to the file containing the data",
        required=True,
    )
    parser.add_argument(
        "-i",
        "--Iterations",
        type=int,
        help="How many iterations the algorithm should perform",
        required=True,
    )
    parser.add_argument(
        "-s", "--Size", type=int, help="Size of the tabu list", required=True
    )

    main(parser.parse_args())
