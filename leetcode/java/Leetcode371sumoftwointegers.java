// LeetCode - 371 - Sum of Two Integers
// Given tow integers a and b, return the sum of these two integers
// Do not use the operators + and -
// ex: a = 2, b = 3. output = 5
//
// Author: Thiru
//
// Time complexity: O(1)
// Space complexity: O(1)

import java.util.*;

class Leetcode371sumoftwointegers {

  // Function to find the sum of two integers
  // Binary addition. Use XOR, AND operators
  public int getSum(int a, int b) {

    while (b != 0) {
      int carry = (a & b & 0x7fffffff) << 1;
      a = a ^ b;
      b = carry;
    }
    return a;
  }

  // main
  public static void main(String[] args)
  {
      int a = 2;
      int b = 3;

      Leetcode371sumoftwointegers obj = new Leetcode371sumoftwointegers();
      System.out.println("Sum of two integers: " + obj.getSum(a, b));
  }
}
