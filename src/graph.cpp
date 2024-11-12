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

    // Create the new node for the edge
    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node in sorted order by destination vertex (v)
    if (adjList[u] == nullptr) {
        adjList[u] = newNode;
    } else {
        pNode temp = adjList[u];
        // Traverse to find the correct insertion point
        while (temp->next != nullptr && temp->next->v < v) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // If the graph is undirected, add the reverse edge
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};
        if (adjList[v] == nullptr) {
            adjList[v] = reverseNode;
        } else {
            pNode temp = adjList[v];
            // Traverse to find the correct insertion point for the reverse edge
            while (temp->next != nullptr && temp->next->v < u) {
                temp = temp->next;
            }
            reverseNode->next = temp->next;
            temp->next = reverseNode;
        }
    }
}


// Method to print the adjacency list for each vertex with exact formatting
void Graph::printAdjList() const {
	for (int i = 0; i < numVertices; i++) {
	        std::cout << "ADJ[" << i + 1 << "]:";
	        pNode temp = adjList[i];
	        while (temp != nullptr) {
	            // Ensure the correct format with a space before the arrow and precision for weights
	            std::cout << " -->[" << temp->u + 1 << " " << temp->v + 1 << ": "
	                      << std::fixed << std::setprecision(2) << temp->weight << "]";
	            temp = temp->next;
	        }
	        std::cout << std::endl;
	    }
}

