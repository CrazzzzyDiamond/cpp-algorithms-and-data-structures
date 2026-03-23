#pragma once
#include <vector>

class Stack
{
private:
  std::vector<int> data;

public:
  void push(int x);
  int pop();
  int peek() const;
  bool isEmpty() const;
  size_t size() const;
};