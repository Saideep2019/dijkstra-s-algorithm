//Saideep Ambari
//1227110055
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"
#include "heap.h"

// Function to create a graph with `n` vertices and `m` edges
pGRAPH createGraph(int n, int m);

// Function to add an edge to the graph
void addEdge(pGRAPH graph, int edgeindex, int u, int v, double w, bool directed, bool flag);

// Function to print the adjacency list of the graph
void printAdjList(pGRAPH graph);

// Function to initialize all vertices with a single source for shortest path algorithms
void initSingleSource(pGRAPH graph, int src);

// Function to relax an edge during shortest path computation
void relax(pGRAPH graph, pHEAP heap, int u, int v, double w);

// Function to compute the shortest path from a single source to a single destination
void singlePair(pGRAPH graph, int src, int dest);

// Function to compute the shortest paths from a single source to all other vertices
void singleSource(pGRAPH graph, int src);

// Function to delete the graph and free allocated memory
void deleteGraph(pGRAPH graph);

#endif
