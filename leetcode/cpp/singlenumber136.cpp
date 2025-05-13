// LeetCode - 136 - Single Number
// Given a non-empty array of integers nums, every element appears twice 
// except for one. Find that single one.
//
// ex: nums = [2,2,1] => 1
// ex: nums = [4,1,2,1,2] => 4
// ex: nums = [1] => 1
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find single number
// Using XOR to find the single occurrence of the number
// XOR of any number with 0 is that number
// XOR of any number with itself is 0

int singleNumber(const std::vector<int>& nums) {
    int missingNumber = 0;

    for (const int& num : nums) {
        missingNumber ^= num;
    }

    return missingNumber;
}

int main() {
    //std::vector<int> nums = {2,2,1};
    std::vector<int> nums = {4,1,2,1,2};
    std::cout<< "Single Number " << singleNumber(nums) << std::endl;

    return 0;
}