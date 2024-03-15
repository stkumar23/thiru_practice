// Given a give m, fill an array (sorted order) starting from 1 to 2*m.
// Lets assume the array as [x1,x2,x3...,xm,y1,y2,y3...ym]
// Rearrange this array to [x1,y1,x2,y2,x3,y3,...,xm,ym]
// Ex: m = 3. Created array = [1,2,3,4,5,6] => [1,4,2,5,3,6]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>

// Function to rearrange the array
// Create an array of size (2*m)
// Add the elements 1 to m and m+1 to 2m in the repeated order
std::vector<int> turnTakeArray(const int& size) {
  std::vector<int> res;
  for (int i=0; i<size; i++) {
    res.push_back(i+1);
    res.push_back(size+i+1);
  }
  return res;
}

// main
int main()
{
  int aSize = 3;

  std::vector<int> res = turnTakeArray(aSize);

  for (const int& i: res) {
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
