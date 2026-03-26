#include <cassert>
#include <iostream>
#include "../../algorithms/merge_sort/merge_sort.h"

int main()
{
  // basic case
  std::vector<int> arr = {8, 3, 1, 6, 4};
  mergeSort(arr);
  assert(arr == std::vector<int>({1, 3, 4, 6, 8}));

  // already sorted
  std::vector<int> arr2 = {1, 2, 3, 4, 5};
  mergeSort(arr2);
  assert(arr2 == std::vector<int>({1, 2, 3, 4, 5}));

  // reverse sorted
  std::vector<int> arr3 = {5, 4, 3, 2, 1};
  mergeSort(arr3);
  assert(arr3 == std::vector<int>({1, 2, 3, 4, 5}));

  // single element
  std::vector<int> arr4 = {42};
  mergeSort(arr4);
  assert(arr4 == std::vector<int>({42}));

  std::cout << "All tests passed\n";
}