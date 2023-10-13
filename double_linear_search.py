from __future__ import annotations


def double_linear_search(array: list[int], search_item: int) -> int:
    start_ind, end_ind = 0, len(array) - 1
    while start_ind <= end_ind:
        if array[start_ind] == search_item:
            return start_ind
        elif array[end_ind] == search_item:
            return end_ind
        else:
            start_ind += 1
            end_ind -= 1
    return -1


if __name__ == "__main__":
    print(double_linear_search(list(range(100)), 40))
