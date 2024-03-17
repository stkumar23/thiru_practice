// LeetCode - 371 - Sum of Two Integers
// Given tow integers a and b, return the sum of these two integers
// Do not use the operators + and -
// ex: a = 2, b = 3. output = 5
//
// Author: Thiru
//
// Time complexity: O(1)
// Space complexity: O(1)

#include <iostream>

// Function to find the sum of two integers
// Binary addition. Use XOR, AND operators
int getSum(int& a, int& b) {

  while (b) {
    int carry = (a & b & 0x7fffffff) << 1;
    a = a ^ b;
    b = carry;
  }
  return a;
}

// main
int main()
{
    int a = 2;
    int b = 3;

    std::cout<<"Sum of two integers: "<<getSum(a, b)<<std::endl;

    return 0;
}
