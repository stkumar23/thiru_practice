// DSA - Search - TernarySearch
// Search an element from a sorted array
// Ex: arr = [1,3,9,15,16,20], numtofind = 16. output = 4
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Ternary Search algorithm
// Divide the array into 3 parts, instead of 2 parts (in binary search)

int ternarySearch(std::vector<int>& arr, const int& num) {
  int low = 0;
  int high = arr.size() - 1;

  while (high >= low) {
    int mid1 = low + (high - low)/3;
    int mid2 = high - (high - low)/3;

    if (arr[mid1] == num) {
      return mid1;
    }

    if (arr[mid2] == num) {
      return mid2;
    }

    if (num < arr[mid1]) {
      high = mid1 - 1;
    } else if (num > arr[mid2]) {
      low = mid2 + 1;
    } else {
      low = mid1 + 1;
      high = mid2 - 1;
    }
  }

  return -1;
}

// main
int main()
{
  std::vector<int> arr = {1,3,9,15,16,20};
  int numToFind = 16;

  std::cout << "Ternary Search " << numToFind << " is found at "
            << ternarySearch(arr, numToFind) << std::endl;

  return 0;
}
