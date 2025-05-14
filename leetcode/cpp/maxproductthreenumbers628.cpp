// LeetCode - 628 - Maximum Product of Three Numbers
// Given an integer array nums, find three numbers whose product is
// maximum and return the maximum product.
//
// ex: nums = [1,2,3] => 6
// ex: nums = [1,2,3,4] => 24
// ex: nums = [-1,-2,-3] => -6
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN, INT_MAX
#include <algorithm> // for std::max

// Function to find maximum product of three numbers
// Find first three largest numbers and get their product
// Find first two minimum numbers and get their product with first max number
// Return the maximum of these two products

int maximumProduct(const std::vector<int>& nums) {
    int firstmax = INT_MIN;
    int secondmax = INT_MIN;
    int thirdmax = INT_MIN;
    int firstmin = INT_MAX;
    int secondmin = INT_MAX;

    for (const int& num: nums) {
        if (num > firstmax) {
            thirdmax = secondmax;
            secondmax = firstmax;
            firstmax = num;
        } else if (num > secondmax) {
            thirdmax = secondmax;
            secondmax = num;
        } else if (num > thirdmax) {
            thirdmax = num;
        }

        if (num < firstmin) {
          secondmin = firstmin;
          firstmin = num;
        } else if (num < secondmin) {
          secondmin = num;
        }
    }

    int firstmaxproduct = firstmax * secondmax * thirdmax;
    int secondmaxproduct = firstmax * firstmin * secondmin;
    return std::max(firstmaxproduct, secondmaxproduct);
}

int main() {
    //std::vector<int> nums = {1,2,3};
    std::vector<int> nums = {1,2,3,4};
    //std::vector<int> nums = {-1,-2,-3};
    std::cout<< "Maximum product value is " << maximumProduct(nums) << std::endl;

    return 0;
}
