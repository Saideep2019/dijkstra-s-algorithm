//Saideep Ambari
//1227110055
#include "util.h"
#include <iostream>
#include <fstream>

bool isValidExecution(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        printErrorAndExit("Usage: ./PJ5 <InputFile> <GraphType> <Flag>");
        return false;
    }

    // Check if the input file can be opened
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        printErrorAndExit("Error: Cannot open input file " + std::string(argv[1]));
        return false;
    }
    inputFile.close();

    // Check if the graph type is valid
    std::string graphType = argv[2];
    if (graphType != "DirectedGraph" && graphType != "UndirectedGraph") {
        printErrorAndExit("Error: <GraphType> must be either DirectedGraph or UndirectedGraph");
        return false;
    }

    // Check if the flag is either 0 or 1
    std::string flagStr = argv[3];
    if (flagStr != "0" && flagStr != "1") {
        printErrorAndExit("Error: <Flag> must be either 0 or 1");
        return false;
    }

    return true;
}

void printErrorAndExit(const std::string& message) {
    std::cerr << message << std::endl;
    exit(1);
}
