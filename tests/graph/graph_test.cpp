#include <cassert>
#include <iostream>
#include "../../data_structures/graph/graph.h"

int main()
{
  Graph g;

  // addNode
  g.addNode(0, 10);
  g.addNode(1, 20);
  g.addNode(2, 30);
  g.addNode(3, 40);

  assert(g.size() == 4);

  // getNode
  assert(g.getNode(0).value == 10);
  assert(g.getNode(2).value == 30);

  // addEdge
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);

  assert(g.hasEdge(0, 1) == true);
  assert(g.hasEdge(0, 3) == false);

  // neighbors
  assert(g.neighbors(0) == std::vector<int>({1, 2}));

  // removeEdge
  g.removeEdge(0, 1);
  assert(g.hasEdge(0, 1) == false);

  // removeNode
  g.removeNode(2);
  assert(g.size() == 3);
  assert(g.hasEdge(0, 2) == false);

  std::cout << "All tests passed\n";
}