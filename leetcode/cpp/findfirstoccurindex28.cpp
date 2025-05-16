// LeetCode - 28 - Find the index of the first occurrence in a string
// Given two strings needle and haystack, return the index of the first
// occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// haystack and needle consist of only lowercase English characters.
//
// ex: haystack = "sadbutsad", needle = "sad" => 0
// ex: haystack = "leetcode", needle = "leeto" => -1
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to find the index of first occurrence in string
// Iterate through the haystack for matched char of needle and
// move to next match char. Otherwise reset the counter, repeat from
// next char of haystack

int strStr(const std::string& haystack, const std::string& needle) {
  int haysize = haystack.size();
  int neesize = needle.size();

  // return -1 in case the needle is empty string
  if (neesize == 0) {
    return -1;
  }

  // return -1 in case the needle is larger than haystack
  if (neesize > haysize) {
    return -1;
  }

  int i = 0;
  int j = 0;
  int count = 0;
  while(i < haysize) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
      count++;
      if (count == neesize) {
        return i - neesize;
      }
    } else {
      i = i - count + 1;
      j = 0;
      count = 0;
    }
  }

  return -1;
}

int main() {
    std::string haystack("sadbutsad");
    std::string needle("sad");

    // std::string haystack("leetcode");
    // std::string needle("leeto");

    std::cout<< "Index of first occurrence " << strStr(haystack, needle) << std::endl;

    return 0;
}
