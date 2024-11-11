#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include "graph.h"
#include <queue>
#include <vector>

// Define DBL_MAX to represent infinity
#include <cfloat>

// Main function to handle input commands and call the appropriate methods
int main() {
    // Example of initializing graph
    int numVertices = 5;  // Example graph with 5 vertices
    Graph graph(numVertices);

    // Load edges from the file
    std::ifstream file("network01.txt");
    std::string line;
    int index = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        int u, v;
        double weight;
        ss >> u >> v >> weight;
        graph.addEdge(index++, u - 1, v - 1, weight);  // Assuming 1-based input, convert to 0-based
    }

    // Handle commands
    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "Stop") {
            break;
        } else if (command == "printAdjList") {
            graph.printAdjList();
        } else {
            std::cerr << "Invalid instruction." << std::endl;
        }
    }

    file.close();
    return 0;
}
