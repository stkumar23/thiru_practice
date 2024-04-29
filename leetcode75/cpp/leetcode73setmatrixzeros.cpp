// LeetCode - 73 - Set Matrix Zeros
// Given an m x n integer matrix matrix, if an element is 0, set its entire
// row and column to 0's.
// ex: matrix = [[1,1,1],[1,0,1],[1,1,1]] => [[1,0,1],[0,0,0],[1,0,1]]
//
// Author: Thiru
//
// Time complexity: O(n2) // n square
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to set matrix zeros
// Read through the matrix and for any zero element, mark its row
// begining and column begining with zero. In case the row is first
// set a flag. Now traverse through the matrix other than first row.
// In case the row or column begining / column set to zero, mark this position
// also. Finally, set all first column and first row to zero based on flag
void setZeros(std::vector<std::vector<int>>& matrix) {
  int rowSize = matrix.size();
  int colSize = matrix[0].size();

  bool firstRow = false;

  for (int i=0; i<rowSize; i++) {
    for (int j=0; j<colSize; j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        if (i>0) {
          matrix[i][0] = 0;
        } else {
          firstRow = true;
        }
      }
    }
  }

  for (int i=1; i<rowSize; i++) {
    for (int j=1; j<colSize; j++) {
      if ((matrix[i][0] == 0) ||  (matrix[0][j] == 0)) {
        matrix[i][j] = 0;
      }
    }
  }

  if (matrix[0][0] == 0) {
    for (int i=0; i<rowSize; i++) {
      matrix[i][0] = 0;
    }
  }

  if (firstRow) {
    for (int i=0; i<colSize; i++) {
      matrix[0][i] = 0;
    }
  }
}

void display(const std::vector<std::vector<int>>& matrix) {
  for (const auto& r: matrix) {
    for (const auto& c: r) {
      std::cout<<c<<" ";
    }
    std::cout<<std::endl;
  }
}

// main
int main()
{
  std::vector<std::vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
  display(m);
  std::cout<<"Output:"<<std::endl;
  setZeros(m);
  display(m);

  return 0;
}
