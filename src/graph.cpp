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

    // Create the new node for edge u -> v
    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node in sorted order in the adjacency list for u
    if (adjList[u] == nullptr) {
        adjList[u] = newNode;
    } else {
        pNode temp = adjList[u];
        pNode prev = nullptr;
        while (temp != nullptr && temp->v < v) { // Sort by destination vertex 'v'
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            newNode->next = adjList[u];
            adjList[u] = newNode;
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    // If the graph is undirected, also add the reverse edge v -> u
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};

        // Insert reverse edge in sorted order in the adjacency list for v
        if (adjList[v] == nullptr) {
            adjList[v] = reverseNode;
        } else {
            pNode temp = adjList[v];
            pNode prev = nullptr;
            while (temp != nullptr && temp->v < u) { // Sort by destination vertex 'u'
                prev = temp;
                temp = temp->next;
            }
            if (prev == nullptr) {
                reverseNode->next = adjList[v];
                adjList[v] = reverseNode;
            } else {
                reverseNode->next = prev->next;
                prev->next = reverseNode;
            }
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

