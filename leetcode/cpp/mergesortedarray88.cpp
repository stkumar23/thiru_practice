// LeetCode - 88 - Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2
// respectively.
//
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//
// ex: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3   => [1,2,2,3,5,6]
// ex: nums1 = [1], m = 1, nums2 = [], n = 0  => [1]
// ex: nums1 = [0], m = 0, nums2 = [1], n = 1 => [1]
//
// Author: Thiru
//
// Time complexity: O(m+n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to merge two sorted arrays in-place
// Get the right index by combining m and n
// Compare each element (from last index. right to left) from nums1 and nums2,
// place the element in right index in nums1. Repeat until all the elements
// from nums2 are inserted into nums1

void merge(std::vector<int>& nums1, const int m, const std::vector<int>& nums2, const int n) {
    int n1_index = m - 1;
    int n2_index = n - 1;
    int right = m + n - 1;

    while (n2_index >= 0) {
        if ((n1_index >= 0) && (nums1[n1_index] > nums2[n2_index])) {
            nums1[right] = nums1[n1_index];
            n1_index--;
        } else {
            nums1[right] = nums2[n2_index];
            n2_index--;
        }
        right--;
    }
}

int main() {
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2 = {2,5,6};
    int n = 3;

    // std::vector<int> nums1 = {0};
    // int m = 0;
    // std::vector<int> nums2 = {1};
    // int n = 1;
    
    merge(nums1, m, nums2, n);

    std::cout<<"The merged array elements: ";
    for (const auto& n : nums1) {
        std::cout<< n << " ";
    }
    std::cout<<std::endl;

    return 0;
}