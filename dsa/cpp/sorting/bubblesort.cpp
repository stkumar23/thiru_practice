// DSA - Sorting - BubbleSort
// Simplest sorting algorithm, repeatedly swapping the adjacent elements if
// they are in wrong order. Stable sorting algorithm
// Ex: arr = [1,9,20,3,16,15] => [1,3,9,15,16,20]
//
// Author: Thiru
//
// Time complexity: O(n2)
// Space complexity: O(1)

#include <iostream>

// Bubble Sort algorithm
// Compare two adjacent elements repeatedly
// Swap the element if they are not in order
void bubbleSort(int a[], const int& s) {
  // in case the given array is already sorted,
  // return after the first pass
  bool isSwapped = false;

  for (int i=0; i<s-1; i++) {
    for (int j=0; j<s-i-1; j++) {
      if (a[j] > a[j+1]) {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;

        if (!isSwapped)
          isSwapped = true;
      }
    }

    if (!isSwapped) {
      break;
    }
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

  int arr[] = {1,9,20,3,16,15};
  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout<<"Array before the sorting"<<std::endl;
  printArray(arr, size);

  bubbleSort(arr, size);

  std::cout<<"Array after the sorting"<<std::endl;
  printArray(arr, size);

  return 0;
}
