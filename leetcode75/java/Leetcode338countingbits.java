// LeetCode - 338 - Counting Bits
// Given an integer n, return an array ans of length n + 1 such that
// for each i (0 <= i <= n), ans[i] is the number of 1's in the binary
// representation of i.
// Ex: n = 2 => [0,1,1]
// Ex: n = 5 => [0,1,1,2,1,2]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;
class Leetcode338countingbits {

  // Function to count the number of 1 bits in each number starting 0 to n
  // Take the reminder of i by 2 and sum it with ans[i/2]
  // ans[0] is 0. Dynamic Programming
  public int[] countBits(int n) {
    int[] ans = new int[n+1];
    ans[0] = 0;

    for (int i=1; i<=n; i++) {
      ans[i] = ans[i/2] + i%2;
    }

    return ans;
  }

  public static void main(String[] args)
  {
    int n = 5;
    Leetcode338countingbits obj = new Leetcode338countingbits();
    int[] res = obj.countBits(n);

    for (int i: res) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
}
