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

import java.util.*;

class InsertionSort {

  // Insertion Sort algorithm
  // Comparing the current element to its predecessor
  public void insertionSort(int[] a) {

    for(int i=1; i<a.length; i++) {
      int j = i;
      int key = a[i];

      while(j>0 && key < a[j-1]) {
        a[j] = a[j-1];
        j -= 1;
      }

      if (i != j)
        a[j] = key;
    }
  }

  public void printArray(int[] a) {
    for (int i=0; i<a.length; i++) {
      System.out.print(a[i] + " ");
    }
    System.out.println();
  }

  // main
  public static void main(String[] args) {

    int[] arr = {45,31,9,20,3,16,15,1};
    System.out.println("Array before the sorting");

    InsertionSort obj = new InsertionSort();

    obj.printArray(arr);

    obj.insertionSort(arr);

    System.out.println("Array after the sorting");
    obj.printArray(arr);
  }
}
