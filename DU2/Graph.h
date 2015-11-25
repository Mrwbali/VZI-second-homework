#pragma once
#include <vector>
#include <set>



class Graph
{

public:

	Graph();

	virtual ~Graph();

private: 

	std::vector<std::vector<std::pair<int,int>>> nodes_vector;

	std::vector<std::pair<int, int>> edges_vector;

public:
	
	struct Result
	{
		std::vector<int> route_vector_;

		int lenght_i_;
	};

	void addNode();

	void addEdge(int node_i, int weight_i);

	Result dijkstraIt(int from_i, int where_i);
};

