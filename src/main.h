#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "graph.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cfloat>

using std::cout;
using std::endl;
// Function to validate command-line arguments
inline bool isValid(int argc, char* argv[]) {
    // Check if correct number of arguments is provided
    if (argc != 4) {
        return false;
    }

    // Check if graph type is valid
    std::string graphType = argv[2];
    if (graphType != "DirectedGraph" && graphType != "UndirectedGraph") {
        return false;
    }

    // Check if flag is a valid integer
    try {
        std::stoi(argv[3]);
    } catch (const std::invalid_argument& e) {
        return false;
    }

    return true;
}

// Function to print usage error when incorrect arguments are provided
inline void printUsageError() {
    std::cerr << "Usage: " << "./program <input_file> <graph_type> <flag>" << std::endl;
    std::cerr << "Graph type must be 'DirectedGraph' or 'UndirectedGraph'" << std::endl;
    std::cerr << "Flag should be an integer" << std::endl;
}

// Function to print an invalid instruction message
inline void printInvalidInstruction() {
    std::cout << "Invalid instruction. Valid instructions are:" << std::endl;
    std::cout << "- Stop" << std::endl;
    std::cout << "- PrintADJ" << std::endl;
    std::cout << "- SinglePair <src> <dest>" << std::endl;
    std::cout << "- SingleSource <src>" << std::endl;
    std::cout << "- PrintLength <src> <dest>" << std::endl;
    std::cout << "- PrintPath <src> <dest>" << std::endl;
}

// Function declarations for other functions that are likely defined elsewhere
void printPath(pGRAPH graph, int src, int dest) {
    // Check if path exists
    if (graph->V[dest]->key == DBL_MAX) {
        cout << "There is no path from " << src << " to " << dest << "." << endl;
        return;
    }

    // Reconstruct the path manually without vector
    int path[100];  // Assuming a max path length of 100
    int pathLength = 0;

    // Collect vertices in the path
    int current = dest;
    while (current != src) {
        path[pathLength++] = current;
        current = graph->V[current]->pi;
    }
    path[pathLength++] = src;

    // Reverse the path manually
    for (int i = 0; i < pathLength / 2; i++) {
        int temp = path[i];
        path[i] = path[pathLength - 1 - i];
        path[pathLength - 1 - i] = temp;
    }

    // Print the path header
    cout << "The shortest path from " << src << " to " << dest << " is: ";

    // Print the path with weights
    for (int i = 0; i < pathLength; ++i) {
        // Print vertex with its distance
        printf("[%d:    %.2lf]", path[i], graph->V[path[i]]->key);

        // Add connection arrow between vertices (except for the last vertex)
        if (i < pathLength - 1) {
            cout << "-->";
        }
    }

    // End the line
    cout << endl;
}

void getInstructions(pGRAPH graph);

#endif // MAIN_H
