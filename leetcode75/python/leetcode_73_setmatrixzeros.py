# LeetCode - 73 - Set Matrix Zeros
# Given an m x n integer matrix matrix, if an element is 0, set its entire
# row and column to 0's.
# ex: matrix = [[1,1,1],[1,0,1],[1,1,1]] => [[1,0,1],[0,0,0],[1,0,1]]
#
# Author: Thiru
#
# Time complexity: O(n2) // n square
# Space complexity: O(1)

from typing import List

class Solution:
    # Function to set matrix zeros
    # Read through the matrix and for any zero element, mark its row
    # begining and column begining with zero. In case the row is first
    # set a flag. Now traverse through the matrix other than first row.
    # In case the row or column begining / column set to zero, mark this position
    # also. Finally, set all first column and first row to zero based on flag
    def setZeros(self, matrix: List[List[int]]) -> None:
      rowSize, colSize = len(matrix), len(matrix[0])
      firstRow = False

      for i in range(rowSize):
        for j in range(colSize):
          if matrix[i][j] == 0:
            matrix[0][j] = 0
            if i>0:
              matrix[i][0] = 0
            else:
              firstRow = True

      for i in range(1, rowSize):
        for j in range(1, colSize):
          if matrix[i][0] == 0 or matrix[0][j] == 0:
            matrix[i][j] = 0

      if matrix[0][0] == 0:
        for i in range(rowSize):
          matrix[i][0] = 0

      if firstRow:
        for i in range(colSize):
          matrix[0][i] = 0

    def display(self, matrix: List[List[int]]) -> None:
        for r in matrix:
            for c in r:
                print(c, end=" ")
            print()

# main
m = [[1,1,1],[1,0,1],[1,1,1]]
obj = Solution()
obj.display(m)
print("Output:")
obj.setZeros(m)
obj.display(m)
