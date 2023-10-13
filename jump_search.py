import math
from collections.abc import Sequence
from typing import Any, Protocol, TypeVar


class Comparable(Protocol):
    def __lt__(self, other: Any, /) -> bool:
        ...


T = TypeVar("T", bound=Comparable)


def jump_search(arr: Sequence[T], item: T) -> int:

    arr_size = len(arr)
    block_size = int(math.sqrt(arr_size))

    prev = 0
    step = block_size
    while arr[min(step, arr_size) - 1] < item:
        prev = step
        step += block_size
        if prev >= arr_size:
            return -1

    while arr[prev] < item:
        prev += 1
        if prev == min(step, arr_size):
            return -1
    if arr[prev] == item:
        return prev
    return -1


if __name__ == "__main__":
    user_input = input("Enter numbers separated by a comma:\n").strip()
    array = [int(item) for item in user_input.split(",")]
    x = int(input("Enter the number to be searched:\n"))

    res = jump_search(array, x)
    if res == -1:
        print("Number not found!")
    else:
        print(f"Number {x} is at index {res}")
