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


    // Ensure adjacency list for both vertices (u and v) exists, initialize them if necessary
    if (adjList[u] == nullptr) {
        adjList[u] = nullptr;
    }
    if (adjList[v] == nullptr) {
        adjList[v] = nullptr;
    }

    // Add edge from u to v
    Node* newNode = new Node();
    newNode->index = index;
    newNode->u = u;
    newNode->v = v;
    newNode->weight = weight;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // If the graph is undirected, add the reverse edge
    if (!isDirected) {
        Node* reverseNode = new Node();
        reverseNode->index = index;
        reverseNode->u = v;
        reverseNode->v = u;
        reverseNode->weight = weight;
        reverseNode->next = adjList[v];
        adjList[v] = reverseNode;
    }
}





// Method to print the adjacency list for each vertex with exact formatting


void Graph::printAdjList() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "ADJ[" << i + 1 << "]:-->";

        // Temporary vector to hold the edges of the current vertex
        pNode temp = adjList[i];

        // Print the edges
        bool first = true;
        while (temp != nullptr) {
            if (!first) {
                std::cout << "-->";
            }
            std::cout << "[" << temp->u + 1 << " " << temp->v + 1 << ": ";
            std::cout << std::fixed << std::setprecision(2) << temp->weight;
            std::cout << "]";
            first = false;
            temp = temp->next;
        }

        std::cout << std::endl;
    }
}

