// LeetCode - 268 - Missing Number
// Given an array containing n distinct numbers in the range [0,n]
// return only the number in the range that is missing from the array
// Ex: nums = [3,0,1] => 2
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find the missing number from the given range 0 to n
// Use XOR operator to find the missing number
// XOR of any number with zero is the same number
// XOR with 0 to n and then XOR with numbers from the given array
// All the numbers will be duplicated except the missing number
int missingNumber(std::vector<int>& v) {
  int res = v.size();

  for (int i=0; i<v.size(); i++) {
    res ^= v[i] ^ i;
  }

  return res;
}

// main
int main()
{
  std::vector<int> nums = {3,0,1};
  std::cout<<"The missing number is "<<missingNumber(nums)<<std::endl;

  return 0;
}
