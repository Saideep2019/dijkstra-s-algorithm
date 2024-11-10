#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

// Structure for an edge node in the adjacency list
struct Node {
    int index;   // Edge index
    int u, v;    // Start and end vertices of the edge
    double weight; // Weight of the edge
    Node* next;  // Pointer to the next node in the adjacency list
};

// Type alias for pointer to Node
typedef Node* pNode;

// Graph class definition
class Graph {
private:
    std::vector<pNode> adjList;  // Adjacency list (vector of pointers to Node)
    int numVertices;  // Number of vertices in the graph
    bool isDirected;  // Flag to determine if the graph is directed
    bool edgeInsertMethod;  // Flag to determine whether to insert edge at front or rear

public:
    // Constructor: Initializes the graph with 'n' vertices and options for directed graph and edge insertion method
    Graph(int n, bool isDirected = false, bool edgeInsertMethod = false);

    // Destructor: Frees the memory allocated for the adjacency list
    ~Graph();

    // Method to add an edge to the graph
    // 'index' is the edge index, 'u' and 'v' are the vertices, and 'weight' is the edge weight
    void addEdge(int index, int u, int v, double weight);

    // Method to print the adjacency list for each vertex
    void printAdjList() const;

    // Method to print the entire graph (all vertices and their connected edges)
    void printGraph() const;
};

#endif // GRAPH_H
