#include <iostream>
#include <iomanip>

class Graph {
private:
    struct Node {
        int index;
        int u, v;
        double weight;
        Node* next;
    };
    using pNode = Node*;

    int numVertices;       // Number of vertices in the graph
    pNode* adjList;        // Array of pointers to nodes (adjacency list)

    bool isDirected;       // Indicates if the graph is directed or undirected

public:
    Graph(int numVertices, bool isDirected = false);  // Constructor
    ~Graph();                                         // Destructor to free memory

    void addEdge(int index, int u, int v, double weight);
    void printGraph() const;
};

// Constructor
Graph::Graph(int numVertices, bool isDirected) : numVertices(numVertices + 1), isDirected(isDirected) {
    adjList = new pNode[this->numVertices]{};  // Initialize adjacency list array with adjusted size
}

// Destructor to free memory
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        pNode temp = adjList[i];
        while (temp != nullptr) {
            pNode next = temp->next;
            delete temp;
            temp = next;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(int index, int u, int v, double weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertex index." << std::endl;
        return;
    }

    // Create a new node for edge u -> v
    pNode newNode = new Node{index, u, v, weight, nullptr};

    // Insert the new node in sorted order for adjacency list of u
    if (adjList[u] == nullptr || adjList[u]->v > v) {
        newNode->next = adjList[u];
        adjList[u] = newNode;
    } else {
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

void Graph::printGraph() const {
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
