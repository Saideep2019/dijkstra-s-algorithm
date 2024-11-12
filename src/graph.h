#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int n, bool isDirected, bool edgeInsertMethod);
    ~Graph();
    void addEdge(int index, int u, int v, double weight);
    void sortAdjList();            // Declaration of sortAdjList
    void printAdjList() const;      // Declaration of printAdjList
    // Other members...

private:
    struct Node {
        int index;
        int u, v;
        double weight;
        Node* next;
    };
    typedef Node* pNode;
    std::vector<pNode> adjList;
    int numVertices;
    bool isDirected;
    bool edgeInsertMethod;
};

#endif // GRAPH_H
