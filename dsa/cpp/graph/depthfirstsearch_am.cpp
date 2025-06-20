// DSA - Graph - Depth First Search
// DFS using Adjacency Matrix
//
// Compile with -std=c++11
// Time complexity O(n * n)
//
// Author: Thiru

#include <iostream>
#include <vector>
#include <stack>

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

// DFS traversal
void depthfirstsearch(const std::vector<std::vector<unsigned int>> &am, unsigned int start) {
    std::vector<bool> visited(am.size(), false);
    std::stack<unsigned int> dfsstack;

    // Set the start node as visited
    dfsstack.emplace(start);
    unsigned int node;

    while (!dfsstack.empty()) {
        node = dfsstack.top();
        dfsstack.pop();

        if (visited[node] != 1) {
            std::cout<<node<<" ";
            visited[node] = true;
            
            for (int i = am.size() - 1; i >= 0; i--) {
                // In case a node is not visited and there is an edge
                if ((am[node][i] == 1) && (!visited[i])) {
                    dfsstack.emplace(i);
                }
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
    // Print order - 0 1 3 2
    //depthfirstsearch(am, 0);

    // start with root node 1
    // Print order - 1 0 2 3
    depthfirstsearch(am, 1);

    return 0;
}