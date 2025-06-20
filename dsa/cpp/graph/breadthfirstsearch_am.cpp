// DSA - Graph - Breadth First Search
// BFS using Adjacency Matrix
//
// Compile with -std=c++11
// Time complexity O(n * n)
//
// Author: Thiru

#include <iostream>
#include <vector>
#include <queue>

// Non-directed Graph Adjacency Matrix
//    0 1 2 3
//    -------
// 0| 0 1 1 0
// 1| 1 0 0 1
// 2| 1 0 0 0
// 3| 0 1 0 0

void updateMatrix(std::vector<std::vector<unsigned int>> &am, unsigned int row, unsigned int col) {
    am[row][col] = 1;
    am[col][row] = 1;
}

// BFS traversal
void breadthfirstsearch(const std::vector<std::vector<unsigned int>> &am, unsigned int start) {
    std::vector<bool> visited(am.size(), false);
    std::queue<unsigned int> bfsqueue;

    // Set the start node as visited
    bfsqueue.emplace(start);
    visited[start] = true;
    unsigned int node;

    while (!bfsqueue.empty()) {
        node = bfsqueue.front();
        bfsqueue.pop();
        std::cout<<node<<" ";

        for (unsigned int i=0; i<am[node].size(); i++) {
            // In case a node is not visited and there is an edge
            if ((am[node][i] == 1) && (!visited[i])) {
                bfsqueue.emplace(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    // number of vertices
    unsigned int n {4};

    // adjacency matrix
    std::vector<std::vector<unsigned int>> am(n, std::vector<unsigned int>(n, 0));

    // fill the matrix with data
    updateMatrix(am, 0, 1);
    updateMatrix(am, 0, 2);
    updateMatrix(am, 1, 3);

    // start with root node 0
    // Print order - 0 1 2 3
    //breadthfirstsearch(am, 0);

    // start with root node 1
    // Print order - 1 0 3 2
    breadthfirstsearch(am, 1);

    return 0;
}