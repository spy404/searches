#include <cassert>
#include <iostream>
#include <vector>

namespace search {
namespace cycle_detection {
template <typename T>
int32_t duplicateNumber(const std::vector<T> &in_arr, const uint32_t &n) {
    if (n == 0 ||
        n == 1) {
        return -1;
    }
    uint32_t tortoise = in_arr[0];
    uint32_t hare =
        in_arr[0];
    do {
        tortoise = in_arr[tortoise];
        hare = in_arr[in_arr[hare]];
    } while (tortoise != hare);
    tortoise = in_arr[0];
    while (tortoise != hare) {
        tortoise = in_arr[tortoise];
        hare = in_arr[hare];
    }
    return tortoise;
}
}
}

static void test() {
    std::vector<uint32_t> array1 = {3, 4, 8, 5, 9, 1, 2, 6, 7, 4};
    std::cout << "Test 1... ";
    assert(search::cycle_detection::duplicateNumber(array1, array1.size()) ==
           4);
    std::cout << "passed" << std::endl;

    std::vector<uint32_t> array2 = {1, 2, 3, 4, 2};
    std::cout << "Test 2... ";
    assert(search::cycle_detection::duplicateNumber(array2, array2.size()) ==
           2);
    std::cout << "passed" << std::endl;

    std::vector<uint32_t> array3 = {};
    std::cout << "Test 3... ";
    assert(search::cycle_detection::duplicateNumber(array3, array3.size()) ==
           -1);
    std::cout << "passed" << std::endl;
}

int main() {
    test();
    return 0;
}
