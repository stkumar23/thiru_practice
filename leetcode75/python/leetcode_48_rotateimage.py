''' LeetCode - 48 - Rotate Image
    Given an n x n 2D matrix representing an image, rotate the image by
    90 degrees (clockwise). Do it in-place
    ex: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [[7,4,1],[8,5,2],[9,6,3]]

    Author: Thiru

    Time complexity: O(n2) n square
    Space complexity: O(1) '''

from typing import List

class Solution:

    ''' Function to rotate the given matrix
        swap the elements [i][j] and [j][i]
        swap the columns. ex: 1 and 3. 1 and 4 and 2 and 3. '''
    def rotate(self, matrix: List[List[int]]) -> None:
        s = len(matrix)
        for i in range(s):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # swap the columns
        for j in range(s//2):
            for i in range(s):
                matrix[i][j], matrix[i][s-1-j] = matrix[i][s-1-j], matrix[i][j]

    def display(self, matrix: List[List[int]]) -> None:
        for r in matrix:
            for c in r:
                print(c , end=" ")
            print()

# main
obj = Solution()
m = [[1,2,3],[4,5,6],[7,8,9]]
obj.display(m)

obj.rotate(m)
print("The rotated matrix")
obj.display(m)
