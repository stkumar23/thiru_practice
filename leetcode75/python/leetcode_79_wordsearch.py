# LeetCode - 79 - Word Search
# Given an m x n grid of characters board and a string word, return true if
# word exists in the grid.
# ex: board = [["A", "B", "C", "E"],["S", "F", "C", "S"],["A", "D", "E", "E"]]
# word = "ABCCED"
#
# Author: Thiru
#
# Time complexity: O(m*n*4^k) // k -> word length
# Space complexity: O(m*n)

from typing import List

class Leadcode79WordSearch:
  # Function to search the given word in the matrix
  # Use DFS to mark the visited element in the matrix
  # Use recursive calls to check the neighbouring elements in the matrix with
  # the remaining characters of the word to find the match
  def exist(self, board: List[List[str]], word: str) -> bool:
      def search(r, c, index) -> bool:

        if index == len(word):
          return True

        if (r<0 or r>=len(board) or c<0 or c>=len(board[0])
            or board[r][c] != word[index]):
            return False

        temp = board[r][c]
        board[r][c] = ''

        if (search(r+1, c, index+1) or
            search(r-1, c, index+1) or
            search(r, c+1, index+1) or
            search(r, c-1, index+1)):
            return True

        board[r][c] = temp
        return False

      r, c = len(board), len(board[0])
      for i in range(r):
          for j in range(c):
              if board[i][j] == word[0] and search(i, j, 0):
                  return True
      return False

# main
obj = Leadcode79WordSearch()
b = [['A', 'B', 'C', 'E'],['S', 'F', 'C', 'S'],['A', 'D', 'E', 'E']];
word = "ABCCED";

print(f"Given word {word} exists in the matrix", obj.exist(b, word))
