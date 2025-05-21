// LeetCode - 26 - Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove 
// the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return
// the number of unique elements in nums.
//
// ex: nums = [1,1,2] => 2
// ex: nums = [0,0,1,1,1,2,2,3,3,4] => 5
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to remove the duplicates in the array - in-place
// Start with the second index from left, compare elements at
// current index and its previous index, place the value at
// the unique index in case those are different.
// Return the unique index

int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 0)
        return 0;

    int j = 1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main() {
    //std::vector<int> nums = {1,1,2};
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    int ret = removeDuplicates(nums);

    std::cout<<"The unique elements in the array " << ret << std::endl;
    for (int i=0; i<ret; i++) {
        std::cout<< nums[i] << " ";
    }
    std::cout<<std::endl;

    return 0;
}