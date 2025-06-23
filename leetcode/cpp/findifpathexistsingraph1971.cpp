// LeetCode - 1971 - Find if Path Exists in Graph
// There is a bi-directional graph with n vertices, where each vertex is
// labeled from 0 to n - 1 (inclusive). The edges in the graph are
// represented as a 2D integer array edges, where each edges[i] = [ui, vi]
// denotes a bi-directional edge between vertex ui and vertex vi. Every
// vertex pair is connected by at most one edge, and no vertex has an edge
// to itself.
//
// You want to determine if there is a valid path that exists from vertex
// source to vertex destination.
//
// Given edges and the integers n, source, and destination, return true
// if there is a valid path from source to destination, or false otherwise.
//
// ex: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2 => true
// ex: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5 => false
//
// Author: Thiru
//
// Time complexity: O(V+E)
// Space complexity: O(V+E)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// Function to find if a path exists between source and destination vertices
// Using BFS traversal
bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    // convert the given edges in adjacency list format
    std::unordered_map<int, std::vector<int>> graph;

    for (const auto& edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    std::queue<int> queue;

    // add source to queue
    queue.push(source);
    visited[source] = true;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        if (node == destination)
            return true;

        // the listnode (vertices) wont be added to the queue
        // for the disconnected portion of the graph
        for (const auto& listnode: graph[node]) {
            if (!visited[listnode]) {
                queue.push(listnode);
                visited[listnode] = true;
            }
        }
    }

    return false;
}

int main() {
    int vertices {3}; //{6};
    int source {0};
    int destination {2}; //{5};
    std::vector<std::vector<int>> edges{{0,1},{1,2},{2,0}};
    //std::vector<std::vector<int>> edges{{0,1},{0,2},{3,5},{5,4},{4,3}};

    std::cout<<"Path Exists "<<validPath(vertices, edges, source, destination)<<std::endl;

    return 0;
}
