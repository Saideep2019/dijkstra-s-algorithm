#ifndef MAIN_H
#define MAIN_H

#include "graph.h"

// Function to validate command-line arguments
bool isValid(int argc, char* argv[]);

// Function to print usage error when incorrect arguments are provided
void printUsageError();

// Function to print an invalid instruction message
void printInvalidInstruction();

// Function to print the shortest path between two vertices
void printPath(pGRAPH graph, int src, int dest);

// Main instruction processing function
void getInstructions(pGRAPH graph);

#endif // MAIN_H
