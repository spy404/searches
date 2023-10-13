#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
namespace search {

namespace binary_search {

uint64_t binarySearch(std::vector<uint64_t> arr, uint64_t val) {
    uint64_t low = 0;
    uint64_t high = arr.size() - 1;

    while (low <= high) {
        uint64_t m = low + (high - low) / 2;

        if (val == arr[m]) {
            return m;
        }
        else if (val < arr[m]) {
            high = m - 1;
        } else {
            low = m + 1;
        }
    }
    return -1;
}

}

}

static void test1() {
    std::vector<uint64_t> arr = {{1, 3, 5, 7, 9, 8, 6, 4, 2}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 3;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 4);
    std::cout << "Test #1: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
}

void test2() {
    std::vector<uint64_t> arr = {{1, 23, 25, 4, 2}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 4;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 25);
    std::cout << "Test #2: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
}

void test3() {
    std::vector<uint64_t> arr = {{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 8;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 31);
    std::cout << "Test #3: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
