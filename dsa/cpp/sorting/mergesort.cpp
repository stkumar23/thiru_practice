// DSA - Sorting - MergeSort
// Merge sort is a recursive algorithm that continuously splits the array in
// half until it cannot be further divided i.e., the array has only one element
// left (an array with one element is always sorted). Then the sorted subarrays
// are merged into one sorted array. Stable sorting algorithm.
// Ex: arr = [45,31,9,20,3,16,15,1] => [1,3,9,15,16,20,31,45]
//
// Author: Thiru
//
// Time complexity: O(nlogn)
// Space complexity: O(n)

#include <iostream>

void merge(int a[], int start, int mid, int end) {
  int left = mid - start + 1;
  int right = end - mid;

  int *leftArray = new int[left];
  int *rightArray = new int[right];

  for (int i=0; i<left; i++) {
    leftArray[i] = a[start+i];
  }

  for (int i=0; i<right; i++) {
    rightArray[i] = a[mid+1+i];
  }

  int i = 0;
  int j = 0;
  int k = start;

  while (i<left && j<right) {
    if (leftArray[i] <= rightArray[j]) {
      a[k] = leftArray[i];
      i++;
    } else {
      a[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while(i<left) {
    a[k] = leftArray[i];
    i++;
    k++;
  }

  while(j<right) {
    a[k] = rightArray[j];
    j++;
    k++;
  }

  delete[] leftArray;
  delete[] rightArray;
}

void mergeSort(int a[], int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = start + (end - start)/2;
  mergeSort(a, start, mid);
  mergeSort(a, mid+1, end);
  merge(a, start, mid, end);
}

void printArray(const int a[], const int& s) {
  for (int i=0; i<s; i++) {
    std::cout<<a[i]<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {45,31,9,20,3,16,15,1};
  int size = sizeof(arr)/sizeof(arr[0]);

  std::cout<<"Array before the sorting"<<std::endl;
  printArray(arr, size);

  mergeSort(arr, 0, size-1);

  std::cout<<"Array after the sorting"<<std::endl;
  printArray(arr, size);
}
