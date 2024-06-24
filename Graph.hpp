#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility> // for pair

using namespace std;

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
    const list<pair<int, double>> &getEdges(int u) const;

    // Print the graph
    void printGraph() const;

private:
    int vertices;
    vector<list<pair<int, double>>> adjacencyList;
};

#endif