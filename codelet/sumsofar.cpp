// Given a list lst filled with integers, replace the integer at nth index
// with the sum so far. The sum so far is equal to the sum of all elements
// that came before and including lst[i]
// Ex: [1,1,1,2,1] => [1,2,3,5,6]
// Ex: [9,8,7,6,1] => [9,17,24,30,31]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1) - in place

#include <iostream>
#include <vector>

// Function to update the sum so far
// Skip the first element, from n[i], i = 1 to n
// add n[i-1] wit n[i]. Do it in-place
std::vector<int> getSumSoFar(std::vector<int>& lst) {

  int size = lst.size();
  if (size == 1)
    return lst;

  for (int i=1; i<size; i++) {
    lst[i] += lst[i-1];
  }

  return lst;
}

// main
int main()
{
  std::vector<int> lst = {1,1,1,2,1};
  //std::vector<int> lst = {9,8,7,6,1};

  std::vector<int> res = getSumSoFar(lst);

  for (const auto& i: res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
