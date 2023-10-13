def median_of_five(arr: list) -> int:
    arr = sorted(arr)
    return arr[len(arr) // 2]


def median_of_medians(arr: list) -> int:
    if len(arr) <= 5:
        return median_of_five(arr)
    medians = []
    i = 0
    while i < len(arr):
        if (i + 4) <= len(arr):
            medians.append(median_of_five(arr[i:].copy()))
        else:
            medians.append(median_of_five(arr[i : i + 5].copy()))
        i += 5
    return median_of_medians(medians)


def quick_select(arr: list, target: int) -> int:
    if target > len(arr):
        return -1

    x = median_of_medians(arr)
    left = []
    right = []
    check = False
    for i in range(len(arr)):
        if arr[i] < x:
            left.append(arr[i])
        elif arr[i] > x:
            right.append(arr[i])
        elif arr[i] == x and not check:
            check = True
        else:
            right.append(arr[i])
    rank_x = len(left) + 1
    if rank_x == target:
        answer = x
    elif rank_x > target:
        answer = quick_select(left, target)
    elif rank_x < target:
        answer = quick_select(right, target - rank_x)
    return answer


print(median_of_five([5, 4, 3, 2]))
