// DSA - Sorting - QuickSort
// Quick sort is based on the divide-and-conquer approach based on the idea of
// choosing one element as a pivot element and partitioning the array around it
// such that: Left side of pivot contains all the elements that are less than
// the pivot element Right side contains all elements greater than the pivot
//
// It reduces the space complexity and removes the use of the auxiliary array
// that is used in merge sort.
//
// Ex: arr = [9,7,8,3,2,1] => [1,2,3,7,8,9]
//
// Author: Thiru
//
// Time complexity: O(nlogn), worst case O(n2)
// Space complexity: O(1)

import java.util.*;

class QuickSort {

  public void printArray(int[] a) {
    for (int i=0; i<a.length; i++) {
      System.out.print(a[i] + " ");
    }
    System.out.println();
  }

  public int partition(int[] a, int start, int end) {
    int piv = a[start];
    int i = start + 1;

    for (int j=start+1; j<=end; j++) {
      if (a[j] < piv) {
        int t = a[j];
        a[j] = a[i];
        a[i] = t;
        i++;
      }
    }

    int t = a[i-1];
    a[i-1] = a[start];
    a[start] = t;

    return i-1;
  }

  public void quickSort(int[] a, int start, int end) {
    if (start >= end)
      return;

    int piv = partition(a, start, end);
    quickSort(a, start, piv);
    quickSort(a, piv+1, end);
  }

  // main
  public static void main(String[] args)
  {
    int[] arr = {9,7,8,3,2,1};

    System.out.println("Array before the sorting");

    QuickSort obj = new QuickSort();
    obj.printArray(arr);

    obj.quickSort(arr, 0, arr.length-1);

    System.out.println("Array after the sorting");
    obj.printArray(arr);
  }
}
