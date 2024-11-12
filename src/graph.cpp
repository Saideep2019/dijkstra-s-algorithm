#include "graph.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

// Method to add an edge to the graph with controlled ordering

Graph::Graph(int n, bool isDirected, bool edgeInsertMethod)
    : numVertices(n), isDirected(isDirected), edgeInsertMethod(edgeInsertMethod) {
    adjList.resize(numVertices, nullptr); // Initialize adjacency list with 'n' null pointers
}


// Destructor
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        pNode current = adjList[i];
        while (current != nullptr) {
            pNode temp = current;
            current = current->next;
            delete temp; // Free each node in the adjacency list
        }
    }
}


void Graph::addEdge(int index, int u, int v, double weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertex index." << std::endl;
        return;
    }

    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node at the beginning
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // Add reverse edge for undirected graphs
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};
        reverseNode->next = adjList[v];
        adjList[v] = reverseNode;
    }
}



// Method to print the adjacency list for each vertex with exact formatting
void Graph::printAdjList() const {
    std::cout << "Adjacency List:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "ADJ[" << i + 1 << "]: ";  // Use 1-based indexing for vertex print
        pNode current = adjList[i];
        while (current != nullptr) {
            std::cout << "-->[" << current->u + 1 << " " << current->v + 1 << ": " << std::fixed << std::setprecision(2) << current->weight << "]";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

