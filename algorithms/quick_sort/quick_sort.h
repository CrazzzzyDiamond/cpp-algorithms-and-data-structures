#pragma once
#include <vector>

void quickSort(std::vector<int> &arr);
void quickSort(std::vector<int> &arr, int left, int right);
int partition(std::vector<int> &arr, int left, int right);