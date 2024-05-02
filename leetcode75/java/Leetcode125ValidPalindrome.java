// LeetCode - 125 - Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and
// numbers. Given a string s, return true if it is a palindrome,
// or false otherwise.
// Ex: s = "A man, a plan, a canal: Panama" => true
//
// Author: Thiru
//
// Time complexity O(n)
// Space complexity O(1)

import java.lang.*;

public class Leetcode125ValidPalindrome {

  // Function to check given string a palindrome or not
  // Use tow pointers, increment/decrement the counter if it encounters
  // non alphanumeric character. Compare the character at either end
  public boolean isPalindrome(String s) {
    int i=0;
    int j=s.length()-1;

    while(i<j) {
      while(!isAlphaNum(s.charAt(i)) && i<j)
        i++;

      while(!isAlphaNum(s.charAt(j)) && i<j)
        j--;

      if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }

  public boolean isAlphaNum(char c) {
    return ((c >= '0') && (c <= '9') ||
      (c >= 'a') && (c <= 'z') ||
      (c >= 'A') && (c <= 'Z'));
  }

  // main
  public static void main(String[] args)
  {
    String s = "A man, a plan, a canal: Panama";
    Leetcode125ValidPalindrome obj = new Leetcode125ValidPalindrome();

    System.out.println("Given string is palindrome " + obj.isPalindrome(s));
  }
}
