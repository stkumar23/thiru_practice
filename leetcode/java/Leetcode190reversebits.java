// LeetCode - 190 - Reverse Bits
// Reverse bits of a given 32 bits integer. (Assume unsignd number)
// Ex: n = 2 (0010) => 0100 0000 0000 0000 0000 0000 0000 0000
// Ex: n = 43261596 => 964176192
//
// Author: Thiru
//
// Time complexity: O(1) // always (32), hence, O(1)
// Space complexity: O(1)

import java.util.*;

class Leetcode190reversebits {

  // Function to reverse the bits of a given number
  // left shift the bits and move it to right, by using right shift operator
  int reverseBits(int n) {
    int res = 0;

    for (int i=0; i<32; i++) {
      if ((n>>i & 1) == 1) {
        res |= 1 << 31 - i;
      }
    }

    return res;
  }

  // main
  public static void main (String[] args)
  {
    int n = 43261596;
    Leetcode190reversebits obj = new Leetcode190reversebits();
    System.out.println("Reverse Bits Output " + obj.reverseBits(n));
  }
}
