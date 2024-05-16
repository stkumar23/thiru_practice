// LeetCode - 647 - Palindromic Substrings
// Given a string s, return the number of palindromic substrings in it.
// ex: s = "abc" => 3
// ex: s = "aaa" => 6
//
// Author: Thiru
//
// Time complexity: O(n2) square
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to check and count the palindromic substrings
// Move the pointer to leftwards and rightwards, check the palindromic substring
int countPalindroms(const std::string& s, int start, int end) {
  int count = 0;
  while(start >=0 && end <s.size() && s[start] == s[end]) {
    count++;
    start--;
    end++;
  }
  return count;
}

int countSubstrings(const std::string& s) {
  int count = 0;
  for (int i=0; i<s.size(); i++) {
    count += countPalindroms(s, i, i);
    count += countPalindroms(s, i, i+1);
  }
  return count;
}

// main
int main()
{
  //std::string s("abc");
  std::string s("aaa");

  std::cout<<"The number of palindromic substrings "<<countSubstrings(s)<<std::endl;

  return 0;
}
