

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

    // Create the new node for the edge u -> v
    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node in sorted order for adjacency list of u
    if (adjList[u] == nullptr || adjList[u]->v > v) {
        // Insert at the beginning if the list is empty or if the first node has a larger v
        newNode->next = adjList[u];
        adjList[u] = newNode;
    } else {
        // Find the correct position and insert in sorted order
        pNode temp = adjList[u];
        while (temp->next != nullptr && temp->next->v < v) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // If the graph is undirected, also add the reverse edge v -> u
    if (!isDirected) {
        pNode reverseNode = new Node{index, v, u, weight, nullptr};

        // Insert the reverse node for the adjacency list of v in sorted order
        if (adjList[v] == nullptr || adjList[v]->v > u) {
            reverseNode->next = adjList[v];
            adjList[v] = reverseNode;
        } else {
            pNode tempReverse = adjList[v];
            while (tempReverse->next != nullptr && tempReverse->next->v < u) {
                tempReverse = tempReverse->next;
            }
            reverseNode->next = tempReverse->next;
            tempReverse->next = reverseNode;
        }
    }
}

// Method to print the adjacency list for each vertex with exact formatting


void Graph::sortAdjList() {
    for (int i = 1; i < numVertices; ++i) {  // Start from index 1 for output consistency
        std::vector<Node*> nodes;
        Node* temp = adjList[i];

        // Collect all nodes in a vector
        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Sort nodes based on destination vertex
        std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->v < b->v;
        });

        // Rebuild linked list from sorted nodes
        adjList[i] = nullptr;
        for (Node* node : nodes) {
            node->next = adjList[i];
            adjList[i] = node;
        }
    }
}


void Graph::printAdjList() const {
    for (int i = 1; i < numVertices; ++i) {  // Start from index 1 for output consistency
        std::cout << "ADJ[" << i << "]:";
        pNode temp = adjList[i];
        while (temp != nullptr) {
            std::cout << "-->[" << temp->u << " " << temp->v << ": "
                      << std::fixed << std::setprecision(2) << temp->weight << "]";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
