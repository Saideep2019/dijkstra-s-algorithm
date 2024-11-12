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

    // Create a new node for the edge from u to v
    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node at the beginning of the adjacency list for vertex u
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // If the graph is undirected, add the reverse edge from v to u
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};
        reverseNode->next = adjList[v];
        adjList[v] = reverseNode;
    }
}

// Method to print the adjacency list for each vertex with exact formatting
void Graph::printAdjList() const {
    std::cout << "Adjacency List:" << std::endl;

    for (int i = 0; i < numVertices; i++) {
        std::cout << "ADJ[" << i + 1 << "]:";

        // Collect all edges for the current vertex
        std::vector<pNode> edges;
        pNode temp = adjList[i];
        while (temp != nullptr) {
            edges.push_back(temp);
            temp = temp->next;
        }

        // Sort edges based on the destination vertex (v)
        std::sort(edges.begin(), edges.end(), [](const pNode& a, const pNode& b) {
            return a->v < b->v;
        });

        // Print all sorted edges
        for (const auto& edge : edges) {
            std::cout << " -->[" << edge->u + 1 << " " << edge->v + 1 << ": "
                      << std::fixed << std::setprecision(2) << edge->weight << "]";
        }
        std::cout << std::endl;
    }
}

