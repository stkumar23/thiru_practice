// LeetCode - 54 - Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Ex: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [1,2,3,6,9,8,7,4,5]
//
// Author: Thiru
//
// Time complexity O(mn)
// Space complexity O(1)

#include <iostream>
#include <vector>

std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
  std::vector<int> res;
  if (matrix.size() == 0)
    return res;

  int r = 0;
  int c = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();

  while (r<rows && c<cols) {
    for (int i=c; i<cols; i++) {
      res.push_back(matrix[r][i]);
    }
    r++;

    for (int i=r; i<rows; i++) {
      res.push_back(matrix[i][cols-1]);
    }
    cols--;

    if (r<rows) {
      for (int i=cols-1; i>=c; i--) {
        res.push_back(matrix[rows-1][i]);
      }
      rows--;
    }

    if (c<cols) {
      for (int i=rows-1; i>=r; i--) {
        res.push_back(matrix[i][c]);
      }
      c++;
    }
  }

  return res;
}

void display(const std::vector<std::vector<int>>& matrix) {
  for (const auto& i: matrix) {
    for (const auto& j: i) {
      std::cout<<j<<" ";
    }
    std::cout<<std::endl;
  }
}

// main
int main()
{
  std::vector<std::vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
  display(m);
  std::vector<int> res = spiralOrder(m);

  for (const auto& i: res) {
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
