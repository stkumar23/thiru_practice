// LeetCode - 48 - Rotate Image
// Given an n x n 2D matrix representing an image, rotate the image by
// 90 degrees (clockwise). Do it in-place
// ex: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [[7,4,1],[8,5,2],[9,6,3]]
//
// Author: Thiru
//
// Time complexity: O(n2) n square
// Space complexity: O(1)

import java.util.*;

public class Leetcode48RotateImage {

  // Function to rotate the given matrix
  // swap the elements [i][j] and [j][i]
  // swap the columns. ex: 1 and 3. 1 and 4 and 2 and 3.
  public void rotate(int[][] matrix) {
    int s = matrix.length;
    for(int i=0; i<s; i++) {
      for(int j=i; j<s; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }

    // swap the columns
    for(int i=0; i<s; i++) {
      for(int j=0; j<s/2; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][s-1-j];
        matrix[i][s-1-j] = temp;
      }
    }
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
  public static void main(String[] args) {
    int[][] m = {{1,2,3},{4,5,6},{7,8,9}};

    Leetcode48RotateImage obj = new Leetcode48RotateImage();
    obj.display(m);

    obj.rotate(m);
    System.out.println("The rotated matrix");
    obj.display(m);
  }
}