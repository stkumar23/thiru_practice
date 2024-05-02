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

#include <iostream>
#include <string>

// Function to check given string a palindrome or not
// Use tow pointers, increment/decrement the counter if it encounters
// non alphanumeric character. Compare the character at either end
bool isPalindrome(std::string s) {

  int i=0;
  int j=s.size()-1;

  while(i<j) {
    while(!std::isalnum(s[i]) && i<j)
      i++;

    while(!std::isalnum(s[j]) && i<j)
      j--;

    if(std::tolower(s[i]) != std::tolower(s[j])) {
      return false;
    }
    i++;
    j--;
  }

  return true;
}

// main
int main()
{
  std::string s("A man, a plan, a canal: Panama");
  std::cout<<"Given string is palindrome "<<std::boolalpha
            <<isPalindrome(s)<<std::endl;
  return 0;
}
