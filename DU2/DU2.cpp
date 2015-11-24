// DU2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "parser.h"
#include "Graph.h"
#include <chrono>
using namespace std::chrono;

int main(int argc, char *argv[])
{
	high_resolution_clock::time_point t1_point = high_resolution_clock::now();
	GraphParser p;
	Problem_t problem;
	Graph graph;

	p.parse("../map/100.map", problem);

	high_resolution_clock::time_point t2_point = high_resolution_clock::now();
	for ( unsigned i = 0; i < problem.edgeList.size(); i++ )
	{
		
		for (unsigned j = 0; j < problem.edgeList.at(i).size(); j++)
		{
			graph.addEdge(problem.edgeList.at(i).at(j), problem.weightList.at(i).at(j));
		}

		graph.addNode();
	}

	high_resolution_clock::time_point t3_point = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2_point - t1_point).count();


	auto duration2 = duration_cast<milliseconds>(t3_point - t2_point).count();


	std::cout << duration << "ms  " << duration2<< "ms";
	
	graph.dijkstraIt(0, 100);

	return 0;
}
