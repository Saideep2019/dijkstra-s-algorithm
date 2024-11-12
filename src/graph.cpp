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
    if (u < 1 || u > numVertices || v < 1 || v > numVertices) {
        std::cerr << "Error: Invalid vertex index." << std::endl;
        return;
    }

    // Adjust u and v to 0-based indexing for internal use
    u--; v--;

    // Create the new node for edge u -> v
    pNode newNode = new Node{index, u + 1, v + 1, weight, nullptr};

    if (edgeInsertMethod) {
        // Insert at rear
        if (!adjList[u]) {
            adjList[u] = newNode;
        } else {
            pNode current = adjList[u];
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    } else {
        // Insert at front
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // If the graph is undirected, also add the reverse edge v -> u
    if (!isDirected) {
        pNode reverseNode = new Node{index, v + 1, u + 1, weight, nullptr};
        if (edgeInsertMethod) {
            // Insert at rear
            if (!adjList[v]) {
                adjList[v] = reverseNode;
            } else {
                pNode current = adjList[v];
                while (current->next) {
                    current = current->next;
                }
                current->next = reverseNode;
            }
        } else {
            // Insert at front
            reverseNode->next = adjList[v];
            adjList[v] = reverseNode;
        }
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

