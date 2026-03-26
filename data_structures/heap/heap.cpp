#include "heap.h"
#include <stdexcept>

Heap::Heap() {}

int Heap::parent(int i) const { return (i - 1) / 2; }
int Heap::leftChild(int i) const { return 2 * i + 1; }
int Heap::rightChild(int i) const { return 2 * i + 2; }

size_t Heap::size() const { return data.size(); }
bool Heap::isEmpty() const { return data.empty(); }

int Heap::peek() const
{
  if (isEmpty())
    throw std::runtime_error("Heap is empty");
  return data[0];
}

void Heap::bubbleUp(int i)
{
  while (i > 0 && data[i] > data[parent(i)])
  {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

void Heap::insert(int value)
{
  data.push_back(value);
  bubbleUp(data.size() - 1);
}

void Heap::bubbleDown(int i)
{
  int largest = i;
  int left = leftChild(i);
  int right = rightChild(i);

  if (left < data.size() && data[left] > data[largest])
    largest = left;

  if (right < data.size() && data[right] > data[largest])
    largest = right;

  if (largest != i)
  {
    std::swap(data[i], data[largest]);
    bubbleDown(largest);
  }
}

int Heap::extractMax()
{
  if (isEmpty())
    throw std::runtime_error("Heap is empty");

  int max = data[0];
  data[0] = data.back();
  data.pop_back();
  bubbleDown(0);
  return max;
}