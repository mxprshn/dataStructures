#include "graph.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Graph
{
	std::vector<std::vector<std::pair<int, int>>> edges;
	std::unordered_map<int, size_t> vertices;
};

Graph *newGraph()
{
	return new Graph;
}

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}

bool exists(Graph *graph, const int vertex)
{
	return graph->vertices.count(vertex) != 0;
}

void addVertex(Graph *graph, const int newVertex)
{
	graph->vertices.insert({newVertex, graph->edges.size()});
	graph->edges.resize(graph->edges.size() + 1);
}

void addEdge(Graph *graph, const int vertexFrom, const int vertexTo, const int edgeLength)
{
	if (!exists(graph, vertexFrom))
	{
		addVertex(graph, vertexFrom);
	}

	if (!exists(graph, vertexTo))
	{
		addVertex(graph, vertexTo);
	}

	graph->edges[graph->vertices[vertexFrom]].push_back({vertexTo, edgeLength});
}

int edgeLength(Graph *graph, const int vertexFrom, const int vertexTo)
{
	if (!exists(graph, vertexFrom) || !exists(graph, vertexTo))
	{
		return -1;
	}

	for (const std::pair<int, int> &current : graph->edges[graph->vertices[vertexFrom]])
	{
		if (current.first == vertexTo)
		{
			return current.second;
		}
	}

	return 0;
}

bool isAdjacent(Graph *graph, const int vertexFrom, const int vertexTo)
{
	return edgeLength(graph, vertexFrom, vertexTo) != 0;
}

std::vector<int> adjacent(Graph *graph, const int vertex)
{
	std::vector<int> result;

	if (!exists(graph, vertex))
	{
		return result;
	}

	for (const std::pair<int, int> &current : graph->edges[graph->vertices[vertex]])
	{
		result.push_back(current.first);
	}

	std::sort(result.begin(), result.end());
	return result;
}

size_t verticesAmount(Graph *graph)
{
	return graph->vertices.size();
}