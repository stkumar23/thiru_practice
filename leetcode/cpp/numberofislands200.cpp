// LeetCode - 200 - Number of islands
// Given an m x n 2D binary grid grid which represents a map of
// '1's (land) and '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all
// four edges of the grid are all surrounded by water.
//
// ex: grid = [["1","1","1","1","0"], ["1","1","0","1","0"],
//             ["1","1","0","0","0"],["0","0","0","0","0"]] => 1
// ex: grid = [["1","1","0","0","0"], ["1","1","0","0","0"],
//             ["0","0","1","0","0"], ["0","0","0","1","1"]] => 3
//
// Author: Thiru
//
// Time complexity: O(V+E)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <stack>


void dfs(std::vector<std::vector<char>>& grid, int x, int y) {
    if (x < 0 || y < 0 ||
        x >= grid.size() ||
        y >= grid[0].size() || grid[x][y] != '1') {
            return;
    }

    // mark the cell with *, hemce, it wont be re-visited
    grid[x][y] = '*';

    // recursive dfs on all neighbours
    dfs(grid, x+1, y);
    dfs(grid, x-1, y);
    dfs(grid, x, y+1);
    dfs(grid, x, y-1);
}

// Function to find the number of islands
// Using the DFS traversal
int numIslands(std::vector<std::vector<char>>& grid) {
    int islands {0};

    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(grid, i, j);
            }
        }
    }
    return islands;
}

int main()
{
    std::vector<std::vector<char>> grid {{'1','1','1','1','0'}, {'1','1','0','1','0'},
                                        {'1','1','0','0','0'}, {'0','0','0','0','0'}};

    // std::vector<std::vector<char>> grid {{'1','1','0','0','0'}, {'1','1','0','0','0'},
    //                                     {'0','0','1','0','0'}, {'0','0','0','1','1'}};

    std::cout<<"Number of Islands "<<numIslands(grid)<<std::endl;

    return 0;
}
