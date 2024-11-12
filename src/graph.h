#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

class Graph {
public:
    Graph(int vertices, bool directed = false);  // Constructor for graph with number of vertices
    void addEdge(int u, int v, double weight);   // Method to add an edge
    void printAdjList() const;                    // Method to print adjacency list
    void shortestPath(int startVertex);           // Method to calculate shortest path

private:
    int numVertices;  // The number of vertices in the graph
    bool isDirected;  // Whether the graph is directed or not
    std::vector<std::list<std::pair<int, double>>> adjList;  // Adjacency list of the graph
};

#endif
