// DU2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "parser.h"
#include "Graph.h"
#include <chrono>
using namespace std::chrono;

int main(int argc, char *argv[])
{
	high_resolution_clock::time_point before_parser_point = high_resolution_clock::now();
	GraphParser p;
	Problem_t problem;
	Graph graph;
	Graph::Result route;

	p.parse("../map/test10k-dir.map", problem);

	high_resolution_clock::time_point after_parser_point = high_resolution_clock::now();
	for ( unsigned i = 0; i < problem.edgeList.size(); i++ )
	{
		
		for (unsigned j = 0; j < problem.edgeList.at(i).size(); j++)
		{
			graph.addEdge(problem.edgeList.at(i).at(j), problem.weightList.at(i).at(j));
		}

		graph.addNode();
	}

	high_resolution_clock::time_point after_make_graph_point = high_resolution_clock::now();

	route = graph.dijkstraIt(0, 9999);
	std::cout << "Route: ";
	for (auto i : route.route_vector_)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Delka: " << route.lenght_i_ << std::endl;

	high_resolution_clock::time_point after_dijkstra_point = high_resolution_clock::now();

	auto time_parser = duration_cast<milliseconds>(after_parser_point - before_parser_point).count();

	auto time_graph = duration_cast<milliseconds>(after_make_graph_point - after_parser_point).count();

	auto time_dijkstra = duration_cast<milliseconds>(after_dijkstra_point - after_make_graph_point).count();

	auto time_complete = duration_cast<milliseconds>(after_dijkstra_point - before_parser_point).count();

	std::cout << "Parser: " << time_parser << " ms"<<std::endl;

	std::cout << "Graph: " << time_graph << " ms" << std::endl;

	std::cout << "Dijkstra: " << time_dijkstra << " ms" << std::endl;

	std::cout << "Complete: " << time_complete << " ms" << std::endl;
	getchar();
	return 0;
}
