// LeetCode - 3005 - Count Elements with Maximum Frequency
// You are given an array nums consisting of positive integers.
// Return the total frequencies of elements in nums such that those elements
// all have the maximum frequency. The frequency of an element is the number
// of occurrences of that element in the array.
//
// ex: nums = [1,2,2,3,1,4] => 4
// ex: nums = [1,2,3,4,5] => 5
//
// Author: Thiru
//
// Time complexity: O(nlogn) // due to sorting
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Function to count maximum frequency of all the elements
// Sort the given array. Find the lower and upper indices for each
// occurrences of the number, get maximum frequency

int maxFrequencyElements(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int fCount = 0;
    int maxFreq = INT_MIN;
    for (int i=0; i<nums.size(); i++) {
        int lidx = std::lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
        int uidx = std::upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin() - 1;
        i = uidx;

        int frequency = uidx-lidx + 1;
        if (frequency > maxFreq) {
            maxFreq = frequency;
            fCount = 1;
        } else if (frequency == maxFreq) {
            fCount++;
        }
    }

    return fCount*maxFreq;
}

int main() {
    std::vector<int> nums = {1,2,2,3,1,4};
    //std::vector<int> nums = {1,2,3,4,5};
    std::cout<< "Sum of Maximum Frequency " << maxFrequencyElements(nums) << std::endl;

    return 0;
}
