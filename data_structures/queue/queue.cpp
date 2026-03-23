#include "queue.h"
#include <stdexcept>

void Queue::enqueue(int x)
{
  data.push_back(x);
}

int Queue::dequeue()
{
  if (isEmpty())
    throw std::runtime_error("Queue is empty");
  int frontElement = data.front();
  data.pop_front();
  return frontElement;
}

int Queue::front() const
{
  if (isEmpty())
    throw std::runtime_error("Queue is empty");
  return data.front();
}

bool Queue::isEmpty() const
{
  return data.empty();
}

size_t Queue::size() const
{
  return data.size();
}