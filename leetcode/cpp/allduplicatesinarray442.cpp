// LeetCode - 442 - Find All Duplicates in an Array
// Given an integer array nums of length n where all the integers of nums
// are in the range [1, n] and each integer appears at most twice, return 
// an array of all the integers that appears twice.Given a valid (IPv4) 
// IP address, return a defanged version of that IP address.
//
// You must write an algorithm that runs in O(n) time and uses only constant
// auxiliary space, excluding the space needed to store the output.
//
// ex: nums = [4,3,2,7,8,2,3,1] => [2,3]
// ex: nums = [1,1,2] => [1]
// ex: nums = [1] => []
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find all duplicates in the array
// Array contains the elements from 1 to n, where n is array size
// Hence, read each array element minus one 1 as index,
// negate that index value. In case the value is already negated,
// add the index + 1 array value in the result which is a duplicate entry

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            res.push_back(idx + 1);
        } else {
            nums[idx] = -nums[idx];
        }
    }

    return res;
}

int main() {
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    //std::vector<int> nums = {1,1,2};
    //std::vector<int> nums = {1};
    std::vector<int> res = findDuplicates(nums);

    for (const auto& n: res) {
        std::cout<< n << " ";
    }
    std::cout<<std::endl;

    return 0;
}