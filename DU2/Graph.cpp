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
	edges_vector.push_back(std::make_pair( node_i, weight_i ));
}

Graph::Result Graph::dijkstraIt(int from_i, int destination_i)
{
	std::vector<std::pair<int, int>> result;
	std::vector< std::pair<int,int> > min_distance_vector(nodes_vector.size(), {INT_MAX,INT_MAX});

	min_distance_vector[from_i] = { 0, 0 };

	std::set< std::pair<int, int> > nodes_set;

	nodes_set.insert({ 0, from_i });

	while (!nodes_set.empty())
	{
		int now_i = nodes_set.begin()->second;
		
		if (now_i == destination_i)
		{
			int now_i = destination_i;

			Result result;

			result.lenght_i_ = min_distance_vector.at(destination_i).second;

			//backtrack
			while (now_i != from_i)
			{
				result.route_vector_.push_back( now_i );

				now_i = min_distance_vector[now_i].first;
			}
			
			result.route_vector_.push_back(now_i);
			std::reverse(result.route_vector_.begin(), result.route_vector_.end());
			return result;
		}

		nodes_set.erase(nodes_set.begin());

		for (auto edge : nodes_vector.at(now_i))
		{
			if (min_distance_vector.at(edge.first).second > min_distance_vector[now_i].second + edge.second)
			{
				nodes_set.erase({ min_distance_vector.at(edge.first).second, edge.first });

				min_distance_vector[edge.first].first = now_i;

				min_distance_vector[edge.first].second = min_distance_vector[now_i].second + edge.second;

				nodes_set.insert({ min_distance_vector[edge.first].second, edge.first });
			}
		}
	}
}
