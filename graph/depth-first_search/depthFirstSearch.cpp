#include "depthFirstSearch.h"
#include "graph.h"
#include <vector>
#include <unordered_set>

void depthSearch(Graph *graph, const int vertex, std::unordered_set<int> &visited)
{
	for (int current : adjacent(graph, vertex))
	{
		if (visited.count(current) == 0)
		{
			visited.insert(current);
			depthSearch(graph, current, visited);
		}
	}
}

std::unordered_set<int> depthFirstSearch(Graph *graph, const int vertex)
{
	std::unordered_set<int> visited;
	visited.insert(vertex);
	depthSearch(graph, vertex, visited);
	return visited;
}

