// DSA - Sorting - SelectionSort
// Simplest sorting algorithm, repeatedly selecting the smallest (or largest)
// element from the unsorted portion of the list and moving it to the sorted
// portion of the list. Not-Stable sorting algorithm. The order of duplicate
// elements are changed, hence, not-stable.
// Ex: arr = [1,9,20,3,16,15] => [1,3,9,15,16,20]
//
// Author: Thiru
//
// Time complexity: O(n2)
// Space complexity: O(1)

#include <iostream>

// Selection Sort algorithm
// Repeatedly mininmum element in each iteration
// Swap the element if min element is found
void selectionSort(int a[], const int& s) {

  for (int i=0; i<s-1; i++) {
    int min = i;

    for (int j=i+1; j<s; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }

    if (min != i) {
      int t = a[i];
      a[i] = a[min];
      a[min] = t;
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

  selectionSort(arr, size);

  std::cout<<"Array after the sorting"<<std::endl;
  printArray(arr, size);

  return 0;
}
