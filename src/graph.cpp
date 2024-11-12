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

    // Insert the new node in sorted order based on destination vertex (v) if needed
    if (edgeInsertMethod) {
        if (adjList[u] == nullptr) {
            adjList[u] = newNode;
        } else {
            pNode temp = adjList[u];
            while (temp->next != nullptr && temp->next->v < v) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    } else { // Insert at the beginning if not maintaining sorted order
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // Add reverse edge for undirected graphs
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};
        if (edgeInsertMethod) {
            if (adjList[v] == nullptr) {
                adjList[v] = reverseNode;
            } else {
                pNode temp = adjList[v];
                while (temp->next != nullptr && temp->next->v < u) {
                    temp = temp->next;
                }
                reverseNode->next = temp->next;
                temp->next = reverseNode;
            }
        } else {
            reverseNode->next = adjList[v];
            adjList[v] = reverseNode;
        }
    }
}


// Method to print the adjacency list for each vertex with exact formatting
void Graph::printAdjList() const {
    std::cout << "Adjacency List:" << std::endl;

    for (int i = 0; i < numVertices; ++i) {
        std::cout << "ADJ[" << i + 1 << "]:";

        pNode current = adjList[i];
        if (current == nullptr) {
            std::cout << std::endl;  // Print empty line for vertices with no edges
            continue;
        }

        while (current != nullptr) {
            // Each edge is printed as [index destination: weight] with fixed precision
            std::cout << "-->[" << current->index << " " << current->v + 1 << ": "
                      << std::fixed << std::setprecision(2) << current->weight << "]";
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
