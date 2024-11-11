#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cfloat>
#include <iomanip>

// Constructor: Initializes the graph with 'n' vertices and options for directed graph and edge insertion method
Graph::Graph(int n, bool isDirected, bool edgeInsertMethod)
    : numVertices(n), isDirected(isDirected), edgeInsertMethod(edgeInsertMethod) {
    adjList.resize(numVertices, nullptr); // Initialize the adjacency list with 'n' null pointers
}

// Destructor: Frees the memory allocated for the adjacency list
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        pNode current = adjList[i];
        while (current != nullptr) {
            pNode temp = current;
            current = current->next;
            delete temp; // Delete each node in the adjacency list
        }
    }
}








// Method to add an edge to the graph
void Graph::addEdge(int index, int u, int v, double weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertex index." << std::endl;
        return;
    }

    pNode newNode = new Node{index, u, v, weight, nullptr}; // Create a new edge node
    std::cout << "Adding edge: " << u + 1 << " --> " << v + 1 << " with weight " << weight << std::endl;

    // Insert the new node at the correct position in the adjacency list
    if (edgeInsertMethod) {
        if (adjList[u] == nullptr) {
            adjList[u] = newNode;
        } else {
            pNode temp = adjList[u];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    } else {
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // If the graph is undirected, add the edge in reverse direction too
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};
        if (edgeInsertMethod) {
            if (adjList[v] == nullptr) {
                adjList[v] = reverseNode;
            } else {
                pNode temp = adjList[v];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = reverseNode;
            }
        } else {
            reverseNode->next = adjList[v];
            adjList[v] = reverseNode;
        }
    }
}


// Method to print the adjacency list for each vertex
void Graph::printAdjList() const {
    std::cout << "Adjacency List:" << std::endl;  // Optional header to align with expected output formatting

    for (int i = 0; i < numVertices; ++i) {
        std::cout << "ADJ[" << i + 1 << "]:";  // Using 1-based indexing for clarity

        pNode current = adjList[i];
        while (current != nullptr) {
            // Each edge is printed with the format [index destination: weight]
            std::cout << "-->[" << current->index << " " << current->v + 1 << ": "
                      << std::fixed << std::setprecision(2) << current->weight << "]";
            current = current->next;
        }

        std::cout << std::endl;  // Ensure each vertex's adjacency list is on a new line
    }

    std::cout << std::endl;  // Additional newline to match output formatting
}








