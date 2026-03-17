#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

#include "../../algorithms/two_pointers/two_pointers.h"

int main()
{
  std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  assert((two_pointers(arr, 12) == std::pair<int, int>{1, 9}));
  assert((two_pointers(arr, 20) == std::pair<int, int>{-1, -1}));
  assert((two_pointers(arr, 3) == std::pair<int, int>{0, 1}));

  std::cout << "All tests passed\n";
}