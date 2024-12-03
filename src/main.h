//Saideep Ambari
//1227110055
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "graph.h"

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
void printPath(pGRAPH graph, int src, int dest);


void getInstructions(pGRAPH graph);

#endif // MAIN_H
