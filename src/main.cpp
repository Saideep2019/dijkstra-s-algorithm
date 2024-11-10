#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Function to load the graph from the input file
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
        // Initialize the graph with the given number of vertices
        g = Graph(n);
    }

    // Read each edge from the file
    int index, u, v;
    double weight;
    while (getline(file, line)) {
        // Print the line for debugging purposes
        cout << "Reading line: " << line << endl;

        stringstream ss(line);

        // Check if the line contains exactly 4 elements: index u v weight
        if (ss >> index >> u >> v >> weight) {
            // Print parsed values for debugging
            cout << "Parsed values: index=" << index << " u=" << u << " v=" << v << " weight=" << weight << endl;

            // Convert from 1-indexed to 0-indexed if needed
            u--; // Convert u from 1-indexed to 0-indexed
            v--; // Convert v from 1-indexed to 0-indexed

            // Check if vertex indices are valid
            if (u >= 0 && u < n && v >= 0 && v < n) {
                // Add the edge to the graph
                g.addEdge(index, u, v, weight);
                cout << "Edge added: " << index << " (" << u + 1 << ", " << v + 1 << ", " << weight << ")" << endl;
            } else {
                cerr << "Error: Invalid vertex index (" << u + 1 << ", " << v + 1 << "). Skipping line: " << line << endl;
            }
        } else {
            // Handle invalid lines (non-edge lines) more gracefully
            cerr << "Ignoring invalid line: " << line << endl;
        }
    }

    file.close();
}



int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./graphApp <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    bool isDirected = (string(argv[2]) == "Directed");
    bool flag = (string(argv[3]) == "1");

    // Initialize the graph (adjust for number of vertices and edges)
    Graph g(8); // Example: 8 vertices for your case

    // Load the graph from the file
    loadGraphFromFile(inputFile, g);

    // Print the adjacency list and graph structure
    cout << "Adjacency List:" << endl;
    g.printAdjList();

    cout << "Entire Graph:" << endl;
    g.printGraph();

    return 0;
}
