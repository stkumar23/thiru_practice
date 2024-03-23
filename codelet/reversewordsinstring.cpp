// Program to reverse the words in a string. Use in place method
// Ex: "have a good day" => "day good a have"
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to reverse the given string
void reverse(std::string& str, int& left, int& right) {
  while (left < right) {
    char c = str[left];
    str[left] = str[right];
    str[right] = c;
    right--;
    left++;
  }
}

// main
int main()
{
  std::string str = "have a good day";

  int left = 0;
  int right = str.size() - 1;

  // reverse the entire string once
  reverse(str, left, right);

  left = 0;
  int i = 0;
  for (; i<str.size(); i++) {
    if (str.at(i) == ' ') {
      right = i-1;
      // reverse each reversed word
      reverse (str, left, right);
      left = i+1;
    }
  }

  // reverse the last reversed word
  right = i-1;
  reverse (str, left, right);

  std::cout<<"The reversed words of a string: " << str << std::endl;

  return 0;
}
