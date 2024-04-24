// LeetCode - 54 - Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Ex: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [1,2,3,6,9,8,7,4,5]
//
// Author: Thiru
//
// Time complexity O(mn)
// Space complexity O(1)

import java.util.*;

public class Leetcode54SpiralMatrix {

  public List<Integer> spiralOrder(int[][] matrix) {

    List<Integer> res = new ArrayList<Integer>();
    if (matrix.length == 0)
      return res;

    int r = 0;
    int c = 0;
    int rows = matrix.length;
    int cols = matrix[0].length;

    while (r<rows && c<cols) {
      for (int i=c; i<cols; i++) {
        res.add(matrix[r][i]);
      }
      r++;

      for (int i=r; i<rows; i++) {
        res.add(matrix[i][cols-1]);
      }
      cols--;

      if (r<rows) {
        for (int i=cols-1; i>=c; i--) {
          res.add(matrix[rows-1][i]);
        }
        rows--;
      }

      if (c<cols) {
        for (int i=rows-1; i>=r; i--) {
          res.add(matrix[i][c]);
        }
        c++;
      }
    }

    return res;
  }

  public void display(int[][] matrix) {
    for(int i=0; i<matrix.length; i++) {
      for(int j=0; j<matrix[i].length; j++) {
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }

  // main
  public static void main(String[] args)
  {
    int[][] m = {{1,2,3},{4,5,6},{7,8,9}};

    Leetcode54SpiralMatrix obj = new Leetcode54SpiralMatrix();
    obj.display(m);

    List<Integer> res = obj.spiralOrder(m);
    for (int i : res) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
}
