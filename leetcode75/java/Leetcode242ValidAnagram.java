// LeetCode - 242 - Valid Anagram
// Given two strings s and t, return true if t is an anagram of s,
// and false otherwise. An Anagram is a word or phrase formed by rearranging
// the letters of a different word or phrase, typically using all the original
// letters exactly once.
// ex: s = "anagram", t = "nagaram"   => true
// ex: s = "rat", t = "car"  => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

public class Leetcode242ValidAnagram {

  // Function to find the given strings are anagram or not
  // Use an array to count the occurrence of each character
  public boolean isAnagram(String s, String t) {
    if (s.length() != t.length())
      return false;

    int[] arr = new int[26];
    for (int i=0; i<s.length(); i++) {
      arr[s.charAt(i)-'a'] += 1;
      arr[t.charAt(i)-'a'] -= 1;
    }

    for (int c : arr) {
      if (c != 0)
        return false;
    }

    return true;
  }

  // main
  public static void main(String[] args)
  {
    String s = "anagram";
    String t = "nagaram";

    Leetcode242ValidAnagram obj = new Leetcode242ValidAnagram();
    System.out.println("Valid Anagram "+ obj.isAnagram(s, t));
  }
}
