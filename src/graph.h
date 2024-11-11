#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <cfloat>

// Structure for an edge node in the adjacency list
struct Node {
    int index;         // Edge index
    int u, v;          // Start and end vertices of the edge
    double weight;     // Weight of the edge
    Node* next;        // Pointer to the next node in the adjacency list
};

typedef Node* pNode;  // Type alias for pointer to Node

class Graph {
private:
    std::vector<pNode> adjList;   // Adjacency list (vector of pointers to Node)
    int numVertices;              // Number of vertices in the graph
    bool isDirected;              // Flag to determine if the graph is directed
    bool edgeInsertMethod;        // Flag to determine edge insertion method
    std::vector<double> key;      // To store shortest distances (Dijkstra’s algorithm)
    std::vector<int> predecessor; // To store the path predecessors (Dijkstra’s algorithm)

    void initializeSingleSource(int source); // Helper for Dijkstra’s

public:
    Graph(int n, bool isDirected = false, bool edgeInsertMethod = false);
    ~Graph();

    void addEdge(int index, int u, int v, double weight);
    void printAdjList() const;
    void printGraph() const;

    // Dijkstra methods and shortest path utilities
    void dijkstraSinglePair(int source, int destination);
    void dijkstraSingleSource(int source);
    void printLength(int s, int t) const;
    void printPath(int s, int t) const;
};

#endif // GRAPH_H
