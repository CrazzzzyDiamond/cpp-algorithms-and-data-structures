#pragma once
#include <vector>

class Heap
{
private:
  std::vector<int> data;

  int parent(int i) const;
  int leftChild(int i) const;
  int rightChild(int i) const;

  void bubbleUp(int i);
  void bubbleDown(int i);

public:
  Heap();

  void insert(int value);
  int extractMax();
  int peek() const;
  size_t size() const;
  bool isEmpty() const;
};