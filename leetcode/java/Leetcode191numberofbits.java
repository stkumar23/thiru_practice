// LeetCode - 191 - Number of 1 Bits
// Write a function that takes the binary representation of an integer
// and returns the number of '1' bits  it has. Also known as Hamming weight.
// ex: n = 1011 => 3
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

class Leetcode191numberofbits {

  // Function to count the number of 1 bits in a number
  // Assume the given number is of 32 bits length
  // Use AND operator Mask, check not equal to zero, to increment the counter.
  // Right shift the number by 1
  public int hammingWeight(int n) {
    int count = 0;
    for (int i=0; i<32; i++) {
      if ((n & 1) !=0 ) {
        count++;
      }
      n >>= 1;
    }

    return count;
  }

  public static void main(String[] args)
  {
    int n = 11;
    Leetcode191numberofbits obj = new Leetcode191numberofbits();
    System.out.println("The number 1 bits " + obj.hammingWeight(n));

  }
}
