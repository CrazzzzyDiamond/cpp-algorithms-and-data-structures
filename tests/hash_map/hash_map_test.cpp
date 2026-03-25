#include <cassert>
#include <iostream>
#include "../../data_structures/hash_map/hash_map.h"

int main()
{
  HashMap m;

  // insert + get
  m.insert(1, 10);
  m.insert(2, 20);
  assert(m.get(1) == 10);
  assert(m.get(2) == 20);

  // size
  assert(m.size() == 2);

  // update
  m.insert(1, 99);
  assert(m.get(1) == 99);
  assert(m.size() == 2);

  // contains
  assert(m.contains(2));
  assert(!m.contains(99));

  // remove
  m.remove(2);
  assert(!m.contains(2));
  assert(m.size() == 1);

  // isEmpty
  m.remove(1);
  assert(m.isEmpty());

  std::cout << "All tests passed\n";
}