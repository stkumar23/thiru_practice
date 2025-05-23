// Find Maximum and Minimum element in an Array
// Given an array nums, find the maximum and minimum elements present in the array.
//
// ex: nums = [4,2,0,8,20,9,2] => max = 20, min = 0
// ex: nums = [-8,-3,-10,-32,-1] => max = -1, min = -32
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>


// Function to find the minimum and maximum elements in the array
// Find the array size. Set both min and max to first element
// of the array for odd size of array. Compare first two elements
// and set the min and max in case of even array size.
// Compare the next two elements and set the min and max. Increment by 2.
// Instead of comparing min and max with each element of array one by one
// compare with two set of values, use increment by 2 to reduce number of
// iterations/comparisons.
void findMinMax(const std::vector<int>& nums, int& min, int& max) {
    int n = nums.size();
    int i = 0;

    if (n%2 != 0) {
        min = nums[0];
        max = nums[0];
        i = 1;
    } else {
        if (nums[0] < nums[1]) {
            min = nums[0];
            max = nums[1];
        } else {
            min = nums[1];
            max = nums[0];
        }
        i = 2;
    }

    while (i < n) {
        if (nums[i] < nums[i+1]) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i+1] > max) {
                max = nums[i+1];
            }
        } else {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i+1] < min) {
                min = nums[i+1];
            }
        }

        i += 2;
    }
}

int main() {
    std::vector<int> nums = {4,2,0,8,20,9,2};
    //std::vector<int> nums = {-8,-3,-10,-32,-1};
    int min;
    int max;

    findMinMax(nums, min, max);

    std::cout<< "The Min and Max values are " << min << " " << max <<std::endl;

    return 0;
}