#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>  // For DBL_MAX

using namespace std;

// Function to load the graph from an input file
void loadGraphFromFile(const string& filename, Graph& g) {
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Read the number of vertices and edges
    int n, m;
    if (getline(file, line)) {
        stringstream ss(line);
        ss >> n >> m;
        g = Graph(n); // Initialize graph with n vertices
    }

    // Read each edge from the file
    int index, u, v;
    double weight;
    while (getline(file, line)) {
        stringstream ss(line);
        if (ss >> index >> u >> v >> weight) {
            g.addEdge(index, u - 1, v - 1, weight); // Adjust to 0-based indexing
        } else {
            cerr << "Ignoring invalid line: " << line << endl;
        }
    }

    file.close();
}

// Main program
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./graphApp <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    bool isDirected = (string(argv[2]) == "Directed");
    bool flag = (string(argv[3]) == "1");

    Graph g(8); // Default initialization, will be re-assigned in loadGraphFromFile
    loadGraphFromFile(inputFile, g);

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    string command;
    cout << "Enter command: ";
    while (getline(cin, command)) {
        if (command == "STOP") {
            cout << "Stopping program." << endl;
            break;
        } else if (command == "printAdjList") {
            g.printAdjList();
        }

//        else if (command.rfind("SinglePair", 0) == 0) {
//            // Parse the SinglePair command
//            stringstream ss(command);
//            string cmd;
//            int source, destination;
//            ss >> cmd >> source >> destination;
//
//            if (source >= 1 && source <= g.numVertices() && destination >= 1 && destination <= g.numVertices()) {
//                g.singlePairDijkstra(source - 1, destination - 1);  // Adjust for 0-based indexing
//                g.printSinglePairPath(source - 1, destination - 1); // Assuming a method to print the path
//            } else {
//                cerr << "Invalid source or destination." << endl;
//            }
//        }

        else {
            cerr << "Invalid instruction." << endl;
        }
        cout << "Enter command: ";
    }

    return 0;
}
