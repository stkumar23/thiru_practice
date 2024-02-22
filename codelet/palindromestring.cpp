// Program to check whether the give string is palindrome or not
// Ex: "kayak" => true
// Ex: "hello" => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to check whether the word is palindrome or not

bool isWordPalindrome(const std::string& str) {

  if (str == "")
    return false;

  int left = 0;
  int right = str.size()-1;

  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    right--;
    left++;
  }
  return true;
}


// main
int main()
{
  std::string word1 = "hello";
  std::string word2 = "kayak";

  std::cout<<"is "<<word1<<" palindrome? "<<std::boolalpha<<isWordPalindrome(word1)<<std::endl;
  std::cout<<"is "<<word2<<" palindrome? "<<isWordPalindrome(word2)<<std::endl;

  return 0;
}
