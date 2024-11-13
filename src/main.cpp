
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
    graph.addEdge(0, 1, 2, 10.00); // Edge (1, 2) with weight 10
    graph.addEdge(1, 1, 4, 5.00);  // Edge (1, 4) with weight 5
    graph.addEdge(2, 2, 3, 1.00);  // Edge (2, 3) with weight 1
   graph. addEdge(3, 2, 4, 2.00);  // Edge (2, 4) with weight 2
    graph.addEdge(4, 3, 5, 4.00);  // Edge (3, 5) with weight 4
    graph.addEdge(5, 4, 2, 3.00);  // Edge (4, 2) with weight 3
    graph.addEdge(6, 4, 3, 9.00);  // Edge (4, 3) with weight 9
    graph.addEdge(7, 4, 5, 2.00);  // Edge (4, 5) with weight 2
    graph.addEdge(8, 5, 1, 7.00);  // Edge (5, 1) with weight 7
   graph. addEdge(9, 5, 3, 6.00);  // Edge (5, 3) with weight 6
    graph.addEdge(10, 6, 3, 7.00); // Edge (6, 3) with weight 7
    graph.addEdge(11, 6, 7, 5.00); // Edge (6, 7) with weight 5
    graph.addEdge(12, 7, 8, 3.00); // Edge (7, 8) with weight 3
    graph.addEdge(13, 8, 6, 1.00); // Edge (8, 6) with weight 1


    // Print the adjacency list of the graph
    graph.printAdjList();

    return 0;
}
