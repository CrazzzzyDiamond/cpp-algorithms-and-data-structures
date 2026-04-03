#include <cassert>
#include <iostream>
#include <vector>

#include "../../algorithms/dfs/dfs.h"
#include "../../data_structures/graph/graph.h"

int main()
{
  // create graph
  Graph g;

  // add nodes
  g.addNode(0, 10);
  g.addNode(1, 20);
  g.addNode(2, 30);
  g.addNode(3, 40);
  g.addNode(4, 40);
  g.addNode(5, 50);
  g.addNode(6, 60);
  g.addNode(7, 70);
  g.addNode(8, 80);

  // add edges
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(0, 4);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  g.addEdge(0, 7);
  g.addEdge(7, 8);

  // test dfs

  // happy path
  std::vector<int> happy_path = dfs(g, 0, 3);
  assert(happy_path == std::vector<int>({0, 1, 2, 3}));

  // no target
  std::vector<int> no_target_path = dfs(g, 0, 99);
  assert(no_target_path == std::vector<int>({}));

  // start == target
  std::vector<int> start_target_path = dfs(g, 0, 0);
  assert(start_target_path == std::vector<int>({0}));

  std::cout << "All tests passed\n";
}