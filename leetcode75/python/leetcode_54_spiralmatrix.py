''' LeetCode - 54 - Spiral Matrix
    Given an m x n matrix, return all elements of the matrix in spiral order.
    Ex: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [1,2,3,6,9,8,7,4,5]

    Author: Thiru

    Time complexity O(mn)
    Space complexity O(1) '''

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        res = []
        r = c = 0
        rows, cols = len(matrix), len(matrix[0])

        while r<rows and c<cols:
            for i in range(c, cols):
                res.append(matrix[r][i])
            r+=1

            for i in range(r, rows):
                res.append(matrix[i][cols-1])
            cols-=1

            if r<rows:
                for i in range(cols-1, c-1, -1):
                    res.append(matrix[rows-1][i])
                rows-=1

            if c<cols:
                for i in range(rows-1, r-1, -1):
                    res.append(matrix[i][c])
                c+=1
        return res

    def display(self, matrix: List[List[int]]) -> None:
        for r in matrix:
            for c in r:
                print(c, end=" ")
            print()

# main
obj = Solution()
m = [[1,2,3],[4,5,6],[7,8,9]]
obj.display(m)

res = obj.spiralOrder(m)
for i in res:
    print(i, end=" ")
print()
