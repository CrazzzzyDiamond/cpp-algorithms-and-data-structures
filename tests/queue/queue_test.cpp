#include <cassert>
#include <iostream>

#include "../../data_structures/queue/queue.h"

int main()
{
  Queue q;

  // enqueue
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  // size
  assert(q.size() == 3);

  // front
  assert(q.front() == 10);

  // dequeue
  assert(q.dequeue() == 10);
  assert(q.dequeue() == 20);

  // isEmpty
  assert(!q.isEmpty());

  assert(q.dequeue() == 30);
  assert(q.isEmpty());

  std::cout << "All tests passed\n";
}