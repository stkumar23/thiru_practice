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

import java.util.*;

class SelectionSort {

  // Selection Sort algorithm
  // Repeatedly mininmum element in each iteration
  // Swap the element if min element is found
  public void selectionSort(int a[]) {
    int s = a.length;

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

  public void printArray(int a[]) {
    for (int i=0; i<a.length; i++) {
      System.out.print(a[i] + " ");
    }
    System.out.println();
  }

  // main
  public static void main(String[] arg) {
    int[] arr = {1,9,20,3,16,15};

    SelectionSort obj = new SelectionSort();
    System.out.println("Array before the sorting");
    obj.printArray(arr);

    obj.selectionSort(arr);

    System.out.println("Array after the sorting");
    obj.printArray(arr);
  }
}
