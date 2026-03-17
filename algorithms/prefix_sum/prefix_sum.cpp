#include "prefix_sum.h"

int prefix_sum(const std::vector<int> &arr, int left, int right)
{
  if (arr.empty())
  {
    return 0;
  }

  std::vector<int> sums(arr.size());

  sums[0] = arr[0];

  for (size_t i = 1; i < arr.size(); i++)
  {
    sums[i] = sums[i - 1] + arr[i];
  }

  if (left == 0)
  {
    return sums[right];
  }

  return sums[right] - sums[left - 1];
}