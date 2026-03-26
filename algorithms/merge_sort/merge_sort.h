#pragma once
#include <vector>

void mergeSort(std::vector<int> &arr);
void mergeSort(std::vector<int> &arr, int left, int right);
void merge(std::vector<int> &arr, int left, int mid, int right);