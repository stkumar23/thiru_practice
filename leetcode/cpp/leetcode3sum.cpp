// LeetCode - 15 - Three Sum
// Given an array of integers nums, return all the triplets [nums[i], nums[j]
// and nums[k]] such that i=!j, i!=k and j!=k and nums[i]+nums[j]+nums[k] = 0
// Solution set should not contain duplicates
// ex: nums = [-1,0,1,2,-1,-4] => [[-1,-1-,2], [-1,0,1]]
//
// Author: Thiru
//
// Time complexity: O(n2) // n square
// Space complexity: O(n) // for sorting it uses O(n)

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the three sum
// Sort the given array. Get the sum of three elements (i, left (i+1) and
// right(from last index)). if the sum is zero, add these elements into the set
// if sum is greater than zero, decrement the right index
// if sum is less than zero, increment the left index
// Check if left and left-1 elements are not equal to avoid duplicates
// Same with right side elements.
std::vector<std::vector<int>> threeSum(std::vector<int>& v) {
  std::vector<std::vector<int>> res;
  int n = v.size();
  std::sort(v.begin(), v.end());

  for (int i=0; i<n-2; i++) {
    if (i>0 && v[i] == v[i-1])
      continue;

    int l = i + 1;
    int r = n - 1;
    while (l < r) {
      int sum = v[i] + v[l] + v[r];
      if (sum > 0) {
        r--;
      } else if (sum < 0) {
        l++;
      } else {
        std::vector<int> t{v[i], v[l], v[r]};
        res.push_back(t);
        l++;
        r--;
        while (l < r && v[l] == v[l-1]) l++;
        while (l < r && v[r] == v[r+1]) r--;
      }
    }
  }

  return res;
}

// main
int main()
{
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> res = threeSum(nums);

    for (const auto& i: res) {
      for (const auto& j: i) {
        std::cout<<j<<" ";
      }
      std::cout<<std::endl;
    }

    return 0;
}
