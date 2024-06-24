#include "Graph.hpp"

// Constructor
Graph::Graph(int vertices) : vertices(vertices)
{
    adjacencyList.resize(vertices);
}

// Add edge
void Graph::addEdge(int u, int v, double weight)
{
    adjacencyList[u].emplace_back(v, weight);
}

// Get the number of vertices
int Graph::getVertices() const
{
    return vertices;
}

// Get the edges
const std::list<std::pair<int, double>> &Graph::getEdges(int u) const
{
    return adjacencyList[u];
}

// Print the graph
void Graph::printGraph() const
{
    for (int u = 0; u < vertices; ++u)
    {
        std::cout << "Vertex " << u << ":";
        for (const auto &edge : adjacencyList[u])
        {
            std::cout << " -> (" << edge.first << ", " << edge.second << ")";
        }
        std::cout << std::endl;
    }
}
