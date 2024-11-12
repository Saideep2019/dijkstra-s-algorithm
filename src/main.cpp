#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // Create a graph with 8 vertices, directed, and edge insert method as true (insert at rear)
    Graph graph(8, true, true);

    // Open the file that contains graph data (change to your file's path)
    std::ifstream file("network01.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Read the number of vertices and edges
    int numVertices, numEdges;
    file >> numVertices >> numEdges;

    // Read edges from the file and add them to the graph
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        file >> u >> v >> weight;

        // Adjust vertex indices to 0-based indexing
        u--;
        v--;

        graph.addEdge(i + 1, u, v, weight); // Assuming 1-based indexing for edge index
    }

    file.close();

    // Print the adjacency list of the graph
    graph.printAdjList();

    return 0;
}
