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

    // Insert the new node at the beginning of the adjacency list for u
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
#include <iostream>
#include <iomanip>  // For std::setprecision and std::fixed

void Graph::printAdjList() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "ADJ[" << i + 1 << "]:-->";

        pNode temp = adjList[i];
        std::vector<pNode> edges;

        // Collect all edges for vertex i
        while (temp != nullptr) {
            edges.push_back(temp);
            temp = temp->next;
        }

        // Print edges for the current vertex
        for (size_t j = 0; j < edges.size(); j++) {
            std::cout << "[" << edges[j]->u + 1 << " " << edges[j]->v + 1 << ": ";

            // Print the weight without decimals if it's a whole number
            if (edges[j]->weight == int(edges[j]->weight)) {
                std::cout << int(edges[j]->weight);  // Print as integer if weight is a whole number
            } else {
                std::cout << std::fixed << std::setprecision(2) << edges[j]->weight;  // Otherwise, print with two decimal places
            }

            std::cout << "]";
            if (j != edges.size() - 1) {
                std::cout << "-->";
            }
        }

        std::cout << std::endl;
    }
}


