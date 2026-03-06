#include "binary_search.h"

int binarySearch(const std::vector<int>& arr, int target) {
	int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (target > arr[mid]) {
      left = arr[mid] + 1;
    }

    if (target < arr[mid]) {
      right = arr[mid] - 1;
    }
  }

  return -1;
}