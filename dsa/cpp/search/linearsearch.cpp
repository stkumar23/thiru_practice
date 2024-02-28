// DSA - Search - LinearSearch
// Search an element from a array. Array is not sorted
// This search is mainly used to find the last occurrence of an element
// Ex: arr = [1,9,3,15,20,18,12], numtofind = 20. output = 4
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Linear Search algorithm
// Search an element in the array from begining to end

int linearSearch(std::vector<int>& arr, const int& num) {
  int size = arr.size();
  int index = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      index = i; // in case just an occurrence is required, return from here
    }
  }

  return index;
}

// main
int main()
{
  std::vector<int> arr = {1,9,3,15,20,18,12};
  int numToFind = 20;

  std::cout << "Linear Search " << numToFind << " is found at "
            << linearSearch(arr, numToFind) << std::endl;

  return 0;
}
