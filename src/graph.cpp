#include "graph.h"
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

Graph::Graph(int vertices, bool directed) : numVertices(vertices), isDirected(directed) {
    adjList.resize(vertices);  // Resize the adjacency list to the number of vertices
}
void Graph::addEdge(int u, int v, double weight) {
    if (u >= numVertices || v >= numVertices) {
        std::cerr << "Error: Invalid vertex index." << std::endl;
        return;
    }

    adjList[u].push_back(std::make_pair(v, weight));  // Add edge u -> v

    if (!isDirected) {
        adjList[v].push_back(std::make_pair(u, weight));  // Add edge v -> u for undirected graphs
    }
}

void Graph::printAdjList() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "ADJ[" << i << "]:";
        for (const auto& edge : adjList[i]) {
            std::cout << "-->" << "[" << i << " " << edge.first << ": " << edge.second << "]";
        }
        std::cout << std::endl;
    }
}

void Graph::shortestPath(int startVertex) {
    std::vector<double> dist(numVertices, INT_MAX);  // Initialize distances with infinity
    dist[startVertex] = 0;

    // Priority queue for Dijkstra's algorithm
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;
    pq.push(std::make_pair(0.0, startVertex));  // Starting vertex with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;
        double uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u]) continue;  // Skip if this distance is outdated

        // Explore the neighbors of u
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            double weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));  // Push the updated distance to the priority queue
            }
        }
    }

    // Print the shortest distances
    std::cout << "The shortest distances from vertex " << startVertex << " are:" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertex " << i << ": " << dist[i] << std::endl;
    }
}
