//
// Created by Renat Norderhaug on 5/16/18.
//

#include <iostream>

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Graph.cpp"
#include "GraphInterface.h"
#include "GraphNode.cpp"
#include "NodeQueue.cpp"

using namespace std;


int main()
{
    Graph x("dijkstra.txt");
    std::cout << " Print Graph is using BFS or DFS \n" << std::endl;
    std::cout << " The initial Flight Map: \n" << std::endl;
    x.printGraph();

    std::cout << "\n The Dijkstra's shortest path from San_Francisco To Tampa \n" << std::endl;
    std::vector<std::string> dik = x.dijkstraShortestPath("San_Francisco", "Tampa");

    for (std::string q : dik)
    {
        std::cout << q << " -> ";
    }
    std::cout << ::endl;

    return 0;
}