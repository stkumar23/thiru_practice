// Codility - Missing Integer
// Write a function: int solution(vector<int> &A);
// that, given an array A of N integers, returns the smallest positive integer
// (greater than 0) that does not occur in A.
// Ex: A = [1, 3, 6, 4, 1, 2], the function should return 5.
// Ex: A = [1, 2, 3], the function should return 4.
// Ex: A = [−1, −3], the function should return 1.
//
// Author: Thiru
//
// Time Complexity: O(nlogn) // for sorting
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the missing number. Sort the given values first.
// Initialize a counter and increment it when it matches with an element from
// the container. The final counter value is the missing number from the
// container.
int solution(std::vector<int> &A)
{
  std::sort(A.begin(), A.end());

  int missingNumber = 1;

  for(const auto& i: A) {
    if(i == missingNumber) {
      missingNumber++;
    }
  }

  return missingNumber;
}

// main
int main()
{
  std::vector<int> v {1, 3, 6, 4, 1, 2};
  std::cout<<"The missing integer: "<<solution(v)<<std::endl;

  return 0;
}
