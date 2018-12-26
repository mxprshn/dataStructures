#pragma once
#include <vector>

struct Graph;

//create new graph and get pointer to it
Graph *newGraph();

//checks a vertex for existence in the graph 
bool exists(Graph *graph, const int vertex);

//add a vertex to the graph
void addVertex(Graph *graph, const int vertex);

//add an edge between two vertices of the graph
void addEdge(Graph *graph, const int vertexFrom, const int vertexTo, const int newLength);

//get vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const int vertex);

//check if one vertex is adjacent to another
bool isAdjacent(Graph *graph, const int vertexFrom, const int vertexTo);

//get length of an edge
int edgeLength(Graph *graph, const int vertexFrom, const int vertexTo);

//deletes graph completely
void deleteGraph(Graph *&graph);

//returns amount of vertices
size_t verticesAmount(Graph *graph);

