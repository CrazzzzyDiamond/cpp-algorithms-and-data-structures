#include "stack.h"
#include <stdexcept>

void Stack::push(int x)
{
  data.push_back(x);
}

int Stack::pop()
{
  if (data.empty())
  {
    throw std::runtime_error("Stack underflow");
  }
  int top = data.back();
  data.pop_back();
  return top;
}

int Stack::peek() const
{
  if (data.empty())
  {
    throw std::out_of_range("Stack is empty");
  }

  return data.back();
}

bool Stack::isEmpty() const
{
  return data.empty();
}

size_t Stack::size() const
{
  return data.size();
}