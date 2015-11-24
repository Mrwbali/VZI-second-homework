#include "Graph.h"


Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addNode()
{
	nodes_vector.push_back(edges_vector);

	edges_vector.clear();
}

void Graph::addEdge(int node_i, int weight_i)
{
	edges_vector.push_back({ { node_i, weight_i } });
}

std::vector<int> Graph::dijkstraIt(int from_i, int where_i)
{	
	int where_im_now_i = from_i;

	std::vector<std::array<int, 2>> distance_vector( nodes_vector.size(),{{INT_MAX, INT_MAX }});
	
	distance_vector.at(from_i)[0] = 0;

	while (!distance_vector.empty())
	{
		
	}
	
	return{ 0, 0 };
}
