// LeetCode - 79 - Word Search
// Given an m x n grid of characters board and a string word, return true if
// word exists in the grid.
// ex: board = [["A", "B", "C", "E"],["S", "F", "C", "S"],["A", "D", "E", "E"]]
// word = "ABCCED"
//
// Author: Thiru
//
// Time complexity: O(m*n*4^k) // k -> word length
// Space complexity: O(m*n)

import java.util.*;

public class Leetcode79WordSearch {
  public boolean search(int r, int c, int index, char[][] board,
              String word, boolean[][] visited) {

    if (index == word.length())
      return true;

    if (r<0 || r>=board.length || c<0 || c>=board[0].length
        || board[r][c] != word.charAt(index) || visited[r][c]) {
        return false;
    }

    visited[r][c] = true;

    if (search(r+1, c, index+1, board, word, visited) ||
        search(r-1, c, index+1, board, word, visited) ||
        search(r, c+1, index+1, board, word, visited) ||
        search(r, c-1, index+1, board, word, visited)) {
        return true;
    }

    visited[r][c] = false;
    return false;
  }

  // Function to search the given word in the matrix
  // Use DFS to mark the visited element in the matrix
  // Use recursive calls to check the neighbouring elements in the matrix with
  // the remaining characters of the word to find the match
  public boolean exists(char[][] board, String word) {

    int r = board.length;
    int c = board[0].length;

    boolean[][] visited = new boolean[r][c];
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        visited[i][j] = false;
      }
    }

    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        if(board[i][j] == word.charAt(0) && search(i, j, 0, board, word, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  // main
  public static void main(String[] args)
  {
    char[][] b = {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    String word = "ABCCED";

    Leetcode79WordSearch obj = new Leetcode79WordSearch();
    System.out.println("Given word "+word+" exists in the matrix " + obj.exists(b, word));
  }
}
