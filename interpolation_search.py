def interpolation_search(sorted_collection, item):
    left = 0
    right = len(sorted_collection) - 1

    while left <= right:
        if sorted_collection[left] == sorted_collection[right]:
            if sorted_collection[left] == item:
                return left
            else:
                return None

        point = left + ((item - sorted_collection[left]) * (right - left)) // (
            sorted_collection[right] - sorted_collection[left]
        )

        if point < 0 or point >= len(sorted_collection):
            return None

        current_item = sorted_collection[point]
        if current_item == item:
            return point
        else:
            if point < left:
                right = left
                left = point
            elif point > right:
                left = right
                right = point
            else:
                if item < current_item:
                    right = point - 1
                else:
                    left = point + 1
    return None


def interpolation_search_by_recursion(sorted_collection, item, left, right):
    if sorted_collection[left] == sorted_collection[right]:
        if sorted_collection[left] == item:
            return left
        else:
            return None

    point = left + ((item - sorted_collection[left]) * (right - left)) // (
        sorted_collection[right] - sorted_collection[left]
    )

    if point < 0 or point >= len(sorted_collection):
        return None

    if sorted_collection[point] == item:
        return point
    elif point < left:
        return interpolation_search_by_recursion(sorted_collection, item, point, left)
    elif point > right:
        return interpolation_search_by_recursion(sorted_collection, item, right, left)
    else:
        if sorted_collection[point] > item:
            return interpolation_search_by_recursion(
                sorted_collection, item, left, point - 1
            )
        else:
            return interpolation_search_by_recursion(
                sorted_collection, item, point + 1, right
            )


def __assert_sorted(collection):
    if collection != sorted(collection):
        raise ValueError("Collection must be ascending sorted")
    return True


if __name__ == "__main__":
    import sys

    debug = 0
    if debug == 1:
        collection = [10, 30, 40, 45, 50, 66, 77, 93]
        try:
            __assert_sorted(collection)
        except ValueError:
            sys.exit("Sequence must be ascending sorted to apply interpolation search")
        target = 67

    result = interpolation_search(collection, target)
    if result is not None:
        print(f"{target} found at positions: {result}")
    else:
        print("Not found")
