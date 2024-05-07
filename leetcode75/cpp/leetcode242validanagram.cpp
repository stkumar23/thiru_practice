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

#include <iostream>
#include <string>

// Function to find the given strings are anagram or not
// Use an array to count the occurrence of each character
bool isAnagram(const std::string& s, const std::string& t) {
  if (s.size() != t.size())
    return false;

  int hash[26] = {0};
  for (int i=0; i<s.size(); i++) {
    hash[s[i]-'a'] += 1;
    hash[t[i]-'a'] -= 1;
  }

  for (int i=0; i<26; i++) {
    if (hash[i] != 0)
      return false;
  }

  return true;
}

// main
int main()
{
  std::string s("anagram");
  std::string t("nagaram");

  std::cout<<"Valid Anagram "<<std::boolalpha<<isAnagram(s, t)<< std::endl;

  return 0;
}
