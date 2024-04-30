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

#include <iostream>
#include <vector>
#include <string>

bool search(int r, int c, int index, const std::vector<std::vector<char>>& board,
            const std::string& word, std::vector<std::vector<bool>>& visited) {

  if (index == word.size())
    return true;

  if (r<0 || r>=board.size() || c<0 || c>=board[0].size()
      || board[r][c] != word[index] || visited[r][c]) {
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
bool exists(const std::vector<std::vector<char>>& board, std::string word) {

  int r = board.size();
  int c = board[0].size();

  std::vector<std::vector<bool>> visited;
  for (int i=0; i<r; i++) {
    std::vector<bool> v(c, false);
    visited.push_back(v);
  }

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      if(board[i][j] == word[0] && search(i, j, 0, board, word, visited)) {
        return true;
      }
    }
  }
  return false;
}

// main
int main()
{
  std::vector<std::vector<char>> b = {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
  std::string word = "ABCCED";

  std::cout<<"Given word "<<word<<" exists in the matrix "
          <<std::boolalpha<<exists(b, word)<<std::endl;

  return 0;
}
