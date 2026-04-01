#pragma once
#include <vector>
#include <unordered_map>

struct Node
{
  int id;
  int value;
};

class Graph
{
private:
  std::unordered_map<int, Node> nodes;
  std::unordered_map<int, std::vector<int>> adjList;

public:
  void addNode(int id, int value);
  void removeNode(int id);
  void addEdge(int fromId, int toId);
  void removeEdge(int fromId, int toId);
  bool hasEdge(int fromId, int toId) const;
  const std::vector<int> &neighbors(int id) const;
  Node getNode(int id) const;
  int size() const;
};