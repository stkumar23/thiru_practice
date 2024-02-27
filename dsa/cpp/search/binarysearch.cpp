// DSA - Search - BinarySearch
// Search an element from a sorted array
// Ex: arr = [1,3,9,15,16,20], numtofind = 16. output = 4
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(1)

#include <iostream>
#include <vector>

// Binary Search algorithm

int binarySearch(std::vector<int>& arr, const int& num) {
  int index = -1;
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int mid = low + (high - low)/2;
    if (arr[mid] == num) {
      return mid;
    }

    if (arr[mid] > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return index;
}

// main
int main()
{
  std::vector<int> arr = {1,3,9,15,16,20};
  int numToFind = 16;

  std::cout << "Binary Search " << numToFind << " is found at "
            << binarySearch(arr, numToFind) << std::endl;

  return 0;
}
