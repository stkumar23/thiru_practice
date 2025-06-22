// LeetCode - 547 - Number of Provinces
// There are n cities. Some of them are connected, while some are not. 
// If city a is connected directly with city b, and city b is connected 
// directly with city c, then city a is connected indirectly with city c.
// Given a non-empty array of integers nums, every element appears twice
//
// A province is a group of directly or indirectly connected cities and 
// no other cities outside of the group.
//
// You are given an n x n matrix isConnected where isConnected[i][j] = 1
// if the ith city and the jth city are directly connected, and 
// isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.
//
// ex: isConnected = [[1,1,0],[1,1,0],[0,0,1]] => 2
// ex: isConnected = [[1,0,0],[0,1,0],[0,0,1]] => 3
//
// Author: Thiru
//
// Time complexity: O(V+E)
// Space complexity: O(V)

#include <iostream>
#include <vector>
#include <stack>


// Function to find the number of provinces
// Using the DFS traversal
// Increment the provinces count only once for the connected paths

int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    std::vector<bool> visited(isConnected.size(), false);
    std::stack<int> dfsstack;
    int provinces {0};

    for (int i=0; i<isConnected.size(); i++) {
        if (!visited[i]) {
            provinces++;
            dfsstack.emplace(i);

            while(!dfsstack.empty()) {
                int node = dfsstack.top();
                dfsstack.pop();
                visited[node] = true;

                for (int j=0; j<isConnected[node].size(); j++) {
                    if ((isConnected[node][j]) == 1 && (!visited[j])) {
                        dfsstack.emplace(j);
                    }
                }
            }
        }
    }

    return provinces;
}

int main()
{
    //std::vector<std::vector<int>> isConnected {{1,1,0}, {1,1,0}, {0,0,1}};
    std::vector<std::vector<int>> isConnected {{1,0,0}, {0,1,0}, {0,0,1}};

    std::cout<<"Number of Provinces "<<findCircleNum(isConnected)<<std::endl;

    return 0;
}
