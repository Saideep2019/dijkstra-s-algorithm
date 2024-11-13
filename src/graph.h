#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    struct Node {
        int index;      // Edge index
        int u, v;       // Source (u) and destination (v) vertices
        double weight;  // Edge weight
        Node* next;     // Pointer to the next node in the list
    };

    typedef Node* pNode;  // Define pNode as a pointer to Node

    // Constructor and Destructor
    Graph(int n, bool isDirected, bool edgeInsertMethod);  // Constructor declaration
    ~Graph();

    // Methods to add edges and print the adjacency list

    void addEdge(int index, int u, int v, double weight);
    void printAdjList() const;

private:
    int numVertices;            // Number of vertices in the graph
    bool isDirected;            // Whether the graph is directed
    bool edgeInsertMethod;      // Whether to insert edges in sorted order
    std::vector<pNode> adjList; // Adjacency list represented as a vector of Node pointers
};

#endif // GRAPH_H
