#include <iostream>
#include <fstream>
#include "graph.h"
#include "main.h"
#include <cfloat>
using namespace std;

int main(int argc,char* argv[]) {
    if (!isValid(argc,argv) ) {
        printUsageError();
        return -1;
    }

    ifstream inFile(argv[1]);
    if (!inFile.is_open() ) {
        cerr << "Error: Open File Not Successful" << endl;
        return -1;
    }

    int n, m;
    inFile >> n >> m;
    pGRAPH graph = createGraph(n,m);
    string graphType = argv[2];
    int flag = stoi(argv[3]);
    bool isDirected = (graphType == "DirectedGraph");
    for (int i = 0; i < m; ++i) {
        int edgeIndex, u, v;
        double w;
        inFile >> edgeIndex >> u >> v >> w;
        addEdge(graph,edgeIndex,u,v,w,isDirected,flag);
    }
    inFile.close();
    getInstructions(graph);
    deleteGraph(graph);
    return 0;
}

void getInstructions(pGRAPH graph) {
    string instruction;
    int src, dest;
    int lastSrc = -1;
    int lastDest = -1;
    while (cin >> instruction) {
        if (instruction == "Stop") {
            break;
        }
        else if (instruction == "PrintADJ") {
            printAdjList(graph);
        }
        else if (instruction == "SinglePair") {
            cin >> src >> dest;
            singlePairShortestPath(graph,src,dest);
            lastSrc = src;
            lastDest = dest;
        }
        else if (instruction == "SingleSource") {
            cin >> src;
            singleSourceShortestPath(graph,src);
            lastSrc = src;
            lastDest = -1;
        }
        else if (instruction == "PrintLength") {
            cin >> src >> dest;
            if (lastSrc == src && (lastDest == dest || lastDest == -1)) {
                if (graph->V[dest]->key == DBL_MAX) {
                    cout << "There is no path from " << src << " to " << dest << "." << endl;
                }
                else {
                    cout << "The length of the shortest path ";
                    printf("from %d to %d is:     %.2lf\n",src,dest,graph->V[dest]->key);
                }
            }
            else {
                cout << "There is no path from " << src << " to " << dest << "." << endl;
            }
        }
        else if (instruction == "PrintPath") {
            cin >> src >> dest;
            if (lastSrc == src && (dest == lastDest || lastDest == -1)) {
                printPath(graph,src,dest);
            }
        }
        else {
            printInvalidInstruction();
        }
    }
}
