
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

    // Print the adjacency list of the graph
    graph.printAdjList();

    return 0;
}
