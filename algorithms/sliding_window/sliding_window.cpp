#include "sliding_window.h"

int sliding_window(const std::vector<int> &arr, int size)
{
  if (size > arr.size())
  {
    return -1;
  }

  int max_sum = 0;
  int window_sum = 0;

  for (int i = 0; i < size; i++)
  {
    window_sum += arr[i];
  }

  max_sum = window_sum;

  for (int i = size; i < arr.size(); i++)
  {
    window_sum += arr[i];
    window_sum -= arr[i - size];

    max_sum = std::max(max_sum, window_sum);
  }

  return max_sum;
}