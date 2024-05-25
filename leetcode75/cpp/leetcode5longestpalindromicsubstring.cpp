// LeetCode - 5 - Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
//
// Ex-1: s = "babad" => bab
// Ex-2: s = "cbbd" => bb
//
// Author: Thiru
//
// Time complexity O(n2) square
// Space complexity O(1)

#include <iostream>
#include <string>

std::string expandFromMiddle(const std::string& s, int start, int end) {

  while (start >= 0 && end < s.length() && s[start] == s[end]) {
    start--;
    end++;
  }

  return s.substr(start+1, end - start - 1);
}


// Function to find the longest palindromic substring
// expand from the middle and find the max length of palindromic substring
std::string longestPalindrome(std::string s) {

  if (s.length() == 0)
    return s;

  std::string maxStr;
  std::string curStr;
  int maxLen = 0;
  int curLen = 0;

  for (int i=0; i<s.length(); i++) {
    curStr = expandFromMiddle(s, i, i);
    curLen = curStr.length();
    if (curLen > maxLen) {
      maxLen = curLen;
      maxStr = curStr;
    }

    curStr = expandFromMiddle(s, i, i+1);
    curLen = curStr.length();
    if (curLen > maxLen) {
      maxLen = curLen;
      maxStr = curStr;
    }
  }

  return maxStr;
}

// main
int main()
{
  std::string s{"babad"};

  std::cout<<"Longest Palindromic Substring "<<longestPalindrome(s)<<std::endl;

  return 0;
}
