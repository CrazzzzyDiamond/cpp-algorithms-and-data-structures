#include "./graph.h"
#include <stdexcept>
#include <algorithm>

void Graph::addNode(int id, int value)
{
  nodes[id] = {id, value};
  adjList[id] = {};
}

void Graph::removeNode(int id)
{
  if (nodes.find(id) == nodes.end())
    throw std::runtime_error("Node not found");

  nodes.erase(id);
  adjList.erase(id);

  for (auto &[nodeId, neighbors] : adjList)
  {
    neighbors.erase(
        std::remove(neighbors.begin(), neighbors.end(), id),
        neighbors.end());
  }
}

Node Graph::getNode(int id) const
{
  if (nodes.find(id) == nodes.end())
    throw std::runtime_error("Node not found");
  return nodes.at(id);
}

int Graph::size() const
{
  return nodes.size();
}

void Graph::addEdge(int fromId, int toId)
{
  if (nodes.find(fromId) == nodes.end() || nodes.find(toId) == nodes.end())
    throw std::runtime_error("Node not found");

  adjList[fromId].push_back(toId);
  adjList[toId].push_back(fromId);
}

void Graph::removeEdge(int fromId, int toId)
{
  adjList[fromId].erase(
      std::remove(adjList[fromId].begin(), adjList[fromId].end(), toId),
      adjList[fromId].end());
  adjList[toId].erase(
      std::remove(adjList[toId].begin(), adjList[toId].end(), fromId),
      adjList[toId].end());
}

bool Graph::hasEdge(int fromId, int toId) const
{
  if (adjList.find(fromId) == adjList.end())
    return false;
  const auto &neighbors = adjList.at(fromId);
  return std::find(neighbors.begin(), neighbors.end(), toId) != neighbors.end();
}

const std::vector<int> &Graph::neighbors(int id) const
{
  if (adjList.find(id) == adjList.end())
    throw std::runtime_error("Node not found");
  return adjList.at(id);
}