// LeetCode - 121 - Best time to buy and sell stock
// You are given an array prices where prices[i] is the price of a given
// stock on the ith day. Maximize your profit by choosing a signle day to
// buy one stock and choosing a different day in the future to sell that
// stock.
// ex: prices = [7,1,5,3,6,4] => 5
// ex: prices = [7,6,4,3,1] => 0
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to find the maximum profit
// Find local min and seacch for local max
// Sliding Window

int maxProfit(const std::vector<int>& prices)
{
  int minVal = prices[0];
  int maxPro = 0;
  int size = prices.size();

  for (int i=0; i<size; i++) {
    maxPro = std::max(prices[i]-minVal, maxPro);
    minVal = std::min(prices[i], minVal);
  }

  return maxPro;
}

// main
int main()
{
  std::vector<int> prices {7,1,5,3,6,4};
  //std::vector<int> prices {7,6,4,3,1};

  std::cout<<"Max Profit " << maxProfit(prices) << std::endl;

  return 0;
}
