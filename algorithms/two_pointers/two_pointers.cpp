#include "two_pointers.h"

std::pair<int, int> two_pointers(const std::vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == target) {
      return std::pair{left, right};
    }

    if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  return std::pair{-1, -1};
}