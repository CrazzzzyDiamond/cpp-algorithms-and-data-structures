#include <iostream>
#include <vector>
#include <cassert>

#include "../../algorithms/sliding_window/sliding_window.h"

int main() {
    std::vector<int> v1{1, 3, -1, -3, 5, 3, 6, 7};
    assert(sliding_window(v1, 3) == 16);

    std::vector<int> v2{-4, -2, -5, -1};
    assert(sliding_window(v2, 2) == -6);

    std::vector<int> v3{2, 4, 6};
    assert(sliding_window(v3, 3) == 12);

    std::vector<int> v4{1, 2};
    assert(sliding_window(v4, 5) == -1);

    std::vector<int> v5{3, 1, 4, 1, 5};
    assert(sliding_window(v5, 1) == 5);

    std::cout << "All tests passed\n";
}
