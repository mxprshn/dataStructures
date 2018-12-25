#pragma once
#include <vector>

//reads graph from adjacency matrix
Graph *readAdjacencyMatrix(const std::vector<std::vector<int>> &matrix);

//reads graph from incidence matrix
Graph *readIncidenceMatrix(const std::vector<std::vector<int>> &matrix);