#pragma once
#include "../../data_structures/graph/graph.h"
#include <vector>

std::vector<int> dfs(const Graph &graph, int startId, int targetId);