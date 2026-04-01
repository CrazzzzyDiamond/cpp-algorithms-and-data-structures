#include <cassert>
#include <iostream>
#include "../../algorithms/quick_sort/quick_sort.h"

int main()
{
  // basic case
  std::vector<int> arr = {8, 3, 1, 6, 4};
  quickSort(arr);
  assert(arr == std::vector<int>({1, 3, 4, 6, 8}));

  // already sorted
  std::vector<int> arr2 = {1, 2, 3, 4, 5};
  quickSort(arr2);
  assert(arr2 == std::vector<int>({1, 2, 3, 4, 5}));

  // reverse sorted
  std::vector<int> arr3 = {5, 4, 3, 2, 1};
  quickSort(arr3);
  assert(arr3 == std::vector<int>({1, 2, 3, 4, 5}));

  // single element
  std::vector<int> arr4 = {42};
  quickSort(arr4);
  assert(arr4 == std::vector<int>({42}));

  std::cout << "All tests passed\n";
}