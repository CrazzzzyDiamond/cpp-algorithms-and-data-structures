#include <cassert>
#include <iostream>
#include "../../data_structures/heap/heap.h"

int main()
{
  Heap h;

  // insert
  h.insert(3);
  h.insert(10);
  h.insert(7);
  h.insert(1);
  h.insert(8);

  // peek
  assert(h.peek() == 10);
  assert(h.size() == 5);

  // extractMax
  assert(h.extractMax() == 10);
  assert(h.extractMax() == 8);
  assert(h.peek() == 7);
  assert(h.size() == 3);

  // isEmpty
  h.extractMax();
  h.extractMax();
  h.extractMax();
  assert(h.isEmpty());

  std::cout << "All tests passed\n";
}