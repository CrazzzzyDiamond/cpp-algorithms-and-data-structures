#include <cassert>
#include <iostream>
#include "../../data_structures/linked_list/linked_list.h"

int main()
{
  LinkedList list;

  list.push_front(10);
  list.push_front(20);
  list.push_back(30);
  assert(!list.isEmpty());
  assert(list.pop_front() == 20);
  assert(list.pop_front() == 10);
  assert(list.pop_front() == 30);

  assert(list.isEmpty());

  std::cout << "All tests passed\n";
}