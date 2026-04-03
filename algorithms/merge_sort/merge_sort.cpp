#include "merge_sort.h"

void merge(std::vector<int> &arr, int left, int mid, int right)
{
  std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
  std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

  int i = 0, j = 0, k = left;

  while (i < leftArr.size() && j < rightArr.size())
  {
    if (leftArr[i] <= rightArr[j])
      arr[k++] = leftArr[i++];
    else
      arr[k++] = rightArr[j++];
  }

  while (i < leftArr.size())
    arr[k++] = leftArr[i++];

  while (j < rightArr.size())
    arr[k++] = rightArr[j++];
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;

  int mid = (left + right) / 2;

  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void mergeSort(std::vector<int> &arr) { mergeSort(arr, 0, arr.size() - 1); }