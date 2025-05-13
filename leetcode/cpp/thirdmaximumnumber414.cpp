// LeetCode - 414 - Third Maximum Number
// Given an integer array nums, return the third distinct maximum number 
// in the array. If the third maximum does not exist, 
// return the maximum number.
//
// ex: nums = [3,2,1] => 1
// ex: nums = [1,2] => 2
// ex: nums = [2,2,3,1] => 1
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN

// Function to find third maximum number
// Initialize three variables with int minimum
// Compare the values and set first max, secondmax and thirdmax
// In case the thirdmax is set to int minimum, return secondmax

int thirdMaximum(const std::vector<int>& nums) {
    int firstmax = INT_MIN;
    int secondmax = INT_MIN;
    int thirdmax = INT_MIN;

    for (const int& num: nums) {
        if (num > firstmax) {
            thirdmax = secondmax;
            secondmax = firstmax;
            firstmax = num;
        } else if ((num < firstmax) && (num > secondmax)) {
            thirdmax = secondmax;
            secondmax = num;
        } else if ((num < secondmax) && (num > thirdmax)) {
            thirdmax = num;
        }
    }

    return thirdmax == INT_MIN ? firstmax : thirdmax;
}

int main() {
    //std::vector<int> nums = {3,2,1};
    std::vector<int> nums = {2,2,3,1};
    //std::vector<int> nums = {1,2};
    std::cout<< "Third Maximum Number " << thirdMaximum(nums) << std::endl;

    return 0;
}