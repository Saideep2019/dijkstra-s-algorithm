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

    // Insert the new node at the end of the adjacency list for u
    if (adjList[u] == nullptr) {
        adjList[u] = newNode;
    } else {
        pNode temp = adjList[u];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // If the graph is undirected, also add the reverse edge v -> u
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};

        // Insert reverse edge at the end of the adjacency list for v
        if (adjList[v] == nullptr) {
            adjList[v] = reverseNode;
        } else {
            pNode temp = adjList[v];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = reverseNode;
        }
    }
}



// Method to print the adjacency list for each vertex with exact formatting


void Graph::printAdjList()  const{
    for (int i = 0; i < numVertices; i++) {
        std::cout << "ADJ[" << i + 1 << "]:-->";

        pNode temp = adjList[i];
        while (temp != nullptr) {
            std::cout << "[" << temp->u + 1 << " " << temp->v + 1 << ": ";

            // Print the weight with two decimal places
            std::cout << std::fixed << std::setprecision(2) << temp->weight;

            std::cout << "]";
            if (temp->next != nullptr) {
                std::cout << "-->";
            }
            temp = temp->next;
        }

        std::cout << std::endl;
    }
}
