#include <cassert>
#include <iostream>

#include "../../data_structures/stack/stack.h"

int main()
{
  Stack s;

  // push
  s.push(10);
  s.push(20);
  s.push(30);

  // size
  assert(s.size() == 3);

  // peek
  assert(s.peek() == 30);

  // pop
  assert(s.pop() == 30);
  assert(s.pop() == 20);

  // isEmpty
  assert(!s.isEmpty());

  assert(s.pop() == 10);
  assert(s.isEmpty());

  std::cout << "All tests passed\n";
}