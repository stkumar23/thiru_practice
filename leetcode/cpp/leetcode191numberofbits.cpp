// LeetCode - 191 - Number of 1 Bits
// Write a function that takes the binary representation of an unsigned integer
// and returns the number of '1' bits  it has. Also known as Hamming weight.
// ex: n = 1011 => 3
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>

// Function to count the number of 1 bits in a number
// Use AND operator to increment the counter.
// Right shift the number by 1
// Repeat until the given number is not zero
int hammingWeight(unsigned int& n) {
  int count = 0;
  while (n > 0) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }

  return count;
}

int main()
{
  unsigned int n = 11;
  std::cout<<"The number 1 bits "<<hammingWeight(n)<<std::endl;

  return 0;
}
