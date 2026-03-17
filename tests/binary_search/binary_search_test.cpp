#include <iostream>
#include <vector>
#include <cassert>

#include "../../algorithms/binary_search/binary_search.h"

int main()
{
  std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  assert(binarySearch(arr, 1) == 0);
  assert(binarySearch(arr, 5) == 4);
  assert(binarySearch(arr, 10) == 9);
  assert(binarySearch(arr, 11) == -1);

  std::cout << "All tests passed\n";
}