// Given an array arr, rotate it number of times.
// Achieve the result using efficient algorithm and do it in-place
// Ex: arr = [1,2,3,4,5,6,7], times = 2 => [6,7,1,2,3,4,5]
// Ex: arr = [1,2,3,4,5,6,7], times = 3 => [5,6,7,1,2,3,4]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>

// Function to reverse the array
void reverseArray(int arr[], int left, int right) {
  while (left < right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++;
    right--;
  }
}

// Function to rotate the array, t times
// Reverse the entire array
// Reverse the first t elements of the array - first portion
// Reverse the elements from the postion t+1 till end the array - last portion
void rotateArray(int arr[], const int& size, const int& t) {

  reverseArray(arr, 0, size-1);
  reverseArray(arr, 0, t-1);
  reverseArray(arr, t, size-1);
}

// main
int main()
{
  int arr[] = {1,2,3,4,5,6,7};
  int times = 3;
  int size = sizeof(arr)/sizeof(arr[0]);

  rotateArray(arr, size, times);

  for (const int& i: arr) {
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
