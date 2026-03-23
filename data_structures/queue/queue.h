#pragma once
#include <deque>

class Queue
{
private:
  std::deque<int> data;

public:
  void enqueue(int x);
  int dequeue();
  int front() const;
  bool isEmpty() const;
  size_t size() const;
};