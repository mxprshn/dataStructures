#pragma once
#include "graph.h"
#include <unordered_set>

//returns set of vertices visited during depth-first-search
std::unordered_set<int> depthFirstSearch(Graph *graph, const int vertex);
