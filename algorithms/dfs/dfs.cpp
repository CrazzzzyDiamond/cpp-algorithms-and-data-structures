#include "dfs.h"
#include <algorithm>

std::vector<int> visitNode(const Graph &graph, std::vector<int> visited,
                           int currentId, int targetId)
{
  visited.push_back(currentId);

  if (currentId == targetId)
    return visited;

  for (int neighborId : graph.neighbors(currentId))
  {
    if (std::find(visited.begin(), visited.end(), neighborId) == visited.end())
    {
      std::vector<int> result = visitNode(graph, visited, neighborId, targetId);
      if (!result.empty())
        return result;
    }
  }

  return {};
}

std::vector<int> dfs(const Graph &graph, int startId, int targetId)
{
  return visitNode(graph, {}, startId, targetId);
}