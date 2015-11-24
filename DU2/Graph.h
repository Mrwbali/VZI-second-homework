#pragma once
#include <vector>
#include <array>
#include <set>

class Node;
class Graph
{

public:

	Graph();

	virtual ~Graph();

private: 

	std::vector<std::vector<std::array<int, 2>>> nodes_vector;

	std::vector<std::array<int, 2>> edges_vector;

public:

	void addNode();

	void addEdge(int node_i, int weight_i);

	std::vector<int> dijkstraIt(int from_i, int where_i);
};

