#include <iostream>
#include <vector>
#include <cassert>

#include "../../algorithms/prefix_sum/prefix_sum.h"

int main() {
    std::vector<int> arr{1,2,3,4,5,6,7,8,9,10};

    int sum = prefix_sum(arr, 3, 7);
    assert(sum == 30);

    int sum2 = prefix_sum(arr, 0, 4);
    assert(sum2 == 15);

    std::cout << "All tests passed\n";
}