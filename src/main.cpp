
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

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int index, u, v;
        double weight;

        // Read the data for each edge in the file (index, u, v, weight)
        if (iss >> index >> u >> v >> weight) {
            // Add the edge to the graph (use the appropriate indices and weight)
            graph.addEdge(index, u - 1, v - 1, weight);  // Assuming 1-based indexing in the file
        }
    }

    // Close the file after reading
    file.close();
    // Manually add an edge for vertex 2 -> vertex 3
    graph.addEdge(0, 1, 2, 1.00);  // Add edge from vertex 2 to vertex 3 (0-indexed)

    // Manually add an edge for vertex 3 -> vertex 4
    graph.addEdge(1, 2, 3, 2.00);  // Add edge from vertex 3 to vertex 4 (0-indexed)

    // Manually add an edge for vertex 4 -> vertex 5
    graph.addEdge(2, 3, 4, 3.00);  // Add edge from vertex 4 to vertex 5 (0-indexed)


    // Print the adjacency list of the graph
    graph.printAdjList();

    return 0;
}
