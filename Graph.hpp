#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility> // for std::pair

class Graph
{
public:
    // Constructor
    Graph(int vertices);

    // Add edge
    void addEdge(int u, int v, double weight);

    // Get the number of vertices
    int getVertices() const;

    // Get the edges
    const std::list<std::pair<int, double>> &getEdges(int u) const;

    // Print the graph
    void printGraph() const;

private:
    int vertices;
    std::vector<std::list<std::pair<int, double>>> adjacencyList;
};

#endif