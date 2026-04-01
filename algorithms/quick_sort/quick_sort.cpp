#include "quick_sort.h"
#include <algorithm>

int partition(std::vector<int> &arr, int left, int right)
{
  int mid = left + (right - left) / 2;
  std::swap(arr[mid], arr[right]);
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[right]);
  return i + 1;
}

void quickSort(std::vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;

  int pivotIndex = partition(arr, left, right);

  quickSort(arr, left, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, right);
}

void quickSort(std::vector<int> &arr)
{
  quickSort(arr, 0, arr.size() - 1);
}