#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
namespace search {

namespace interpolation_search {

uint64_t interpolationSearch(const std::vector<uint64_t> &arr,
                             uint64_t number) {
    uint64_t size = arr.size();
    uint64_t low = 0, high = (size - 1);

    while (low <= high && number >= arr[low] && number <= arr[high]) {
        if (low == high) {
            if (arr[low] == number) {
                return low;
            }
            return -1;
        }
        uint64_t pos =
            low +
            ((static_cast<uint64_t>(high - low) / (arr[high] - arr[low])) *
             (number - arr[low]));

        if (arr[pos] == number) {
            return pos;
        }

        if (arr[pos] < number) {
            low = pos + 1;
        }

        else {
            high = pos - 1;
        }
    }
    return -1;
}

}
}
static void tests() {
    std::vector<uint64_t> arr = {{10, 12, 13, 16, 18, 19, 20, 21, 1, 2, 3, 4,
                                  22, 23, 24, 33, 35, 42, 47}};
    sort(arr.begin(), arr.end());
    uint64_t number = 33;
    uint64_t expected_answer = 15;
    uint64_t derived_answer =
        search::interpolation_search::interpolationSearch(arr, number);
    std::cout << "Testcase: ";
    assert(derived_answer == expected_answer);
    std::cout << "Passed!\n";
}

int main() {
    tests();
    return 0;
}
