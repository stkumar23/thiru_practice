// LeetCode - 26 - Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove 
// the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return
// the number of unique elements in nums.
//
// ex: nums = [1,1,2] => 2
// ex: nums = [0,0,1,1,1,2,2,3,3,4] => 5
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

class RemoveDupFromSortedArray26 {

    // Function to remove the duplicates in the array - in-place
    // Start with the second index from left, compare elements at
    // current index and its previous index, place the value at
    // the unique index in case those are different.
    // Return the unique index

    public int removeDuplicates(int[] nums) {
        if (nums.length <= 0)
            return 0;

        int j = 1;
        for (int i=1; i < nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }

    public static void main(String[] args) {
        //int[] nums = {1,1,2};
        int[] nums = {0,0,1,1,1,2,2,3,3,4};

        RemoveDupFromSortedArray26 obj = new RemoveDupFromSortedArray26();
        int ret = obj.removeDuplicates(nums);

        System.out.println("The unique elements in the array " + ret);
        for (int i=0; i<ret; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();

    }
}