// DSA - Sorting - InsertionSort
// Simplest sorting algorithm, repeatedly selecting one element from the array
// is consumed in each iteration to find its correct position. Comparing the
// current element to its predecessor. Stable sorting algorithm.
// Ex: arr = [45,31,9,20,3,16,15,1] => [1,3,9,15,16,20,31,45]
//
// Author: Thiru
//
// Time complexity: O(n2)
// Space complexity: O(1)

#include <iostream>

// Insertion Sort algorithm
// Comparing the current element to its predecessor
void insertionSort(int a[], const int& s) {

  for (int i=1; i<s; i++) {
    int j = i;
    int key = a[i];

    while (j>0 && key < a[j-1]) {
      a[j] = a[j-1];
      j -= 1;
    }

    if (i != j)
      a[j] = key;
  }
}

void printArray(const int a[], const int& s) {
  for (int i=0; i<s; i++) {
    std::cout<<a[i]<<" ";
  }
  std::cout<<std::endl;
}

// main
int main() {

  int arr[] = {45,31,9,20,3,16,15,1};
  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout<<"Array before the sorting"<<std::endl;
  printArray(arr, size);

  insertionSort(arr, size);

  std::cout<<"Array after the sorting"<<std::endl;
  printArray(arr, size);

  return 0;
}
