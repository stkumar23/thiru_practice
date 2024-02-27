// Find a specified number's index in a sorted array.
// Return the index if it exists, otherwise -1.
// Ex: arr = [-1,1,3,9], numtofind = 3. output = 2
// Ex: arr = [-1,1,3,9], numtofind = 6. output = -1
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Function to get the element index from the sorted array
// Array is sorted, so use binary search to find the element index

int getElementIndex(std::vector<int>& arr, const int& num) {
  int res = -1;
  int left = 0;
  int right = arr.size() - 1;

  while (right - left >= 0) {
    int mid = left + (right - left)/2;
    if (arr[mid] == num) {
      return mid;
    }

    if (arr[mid] > num) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return res;
}

// main
int main()
{
  std::vector<int> arr = {-1,1,3,9};
  int numToFind = -1;

  std::cout << numToFind << " is found at " << getElementIndex(arr, numToFind)
            << std::endl;

  return 0;
}
