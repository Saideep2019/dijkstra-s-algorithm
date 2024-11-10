#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>  // For DBL_MAX (to define infinity for graph algorithms)

// Define COLOR enum for vertex state in algorithms like BFS/DFS
enum COLOR {
    WHITE,  // Vertex not visited yet
    GRAY,   // Vertex is being visited (explored)
    BLACK   // Vertex fully explored
};

// Define VERTEX structure for graph vertex
struct VERTEX {
    int index;    // Vertex index (ID)
    COLOR color;  // Vertex color for graph traversal
    double key;   // Key value for algorithms like Prim's MST or Dijkstra's shortest path
    int pi;       // Parent vertex in shortest path or MST
    int position; // Position for data structure (e.g., heap position)
};

// Pointer to a VERTEX
typedef VERTEX* pVERTEX;

// Define NODE structure for adjacency list (used in graph representation)
struct NODE {
    int index;  // Edge index (identifier)
    int u, v;   // Vertices u and v representing an edge between them
    double w;   // Weight of the edge
    NODE* next; // Pointer to next node in adjacency list (for u or v)
};

// Pointer to a NODE
typedef NODE* pNODE;

// Constant for infinity, used in graph algorithms like Dijkstra or Prim
const double INF = DBL_MAX;

#endif // DATA_STRUCTURES_H
