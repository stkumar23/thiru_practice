// Program to find the position of close parentheses for a given
// open parentheses
// Ex: Sample problem (taken from (internet (web)), for a practice)
// position: 27 (zeroth index) => output: 42
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to find the position of close parentheses for a open parentheses
// at a given position. Set a counter and increment it if any inner open
// parentheses is found. Decrement this counter for a correponding close
// parentheses. In case the counter is zero when encountering a close
// parentheses, return the position.
// Return -1, in case a open parentheses is not found in the given position.

int findCloseParenthesesPosition(const std::string& s, const int& pos) {
  int openParenCount = 0;

  if (s.at(pos) == '(') {
    for (int i=pos+1; i<s.length(); i++) {
      if (s.at(i) == ')') {
        if (openParenCount == 0) {
          return i;
        } else {
          openParenCount--;
        }
      } else if (s.at(i) == '(') {
        openParenCount++;
      }
    }
  }

  return -1;
}


// main
int main()
{
  std::string str("Sample problem (taken from (internet (web)), for a practice)");
  int position = 27;

  std::cout<<"The close parentheses is found at "
            <<findCloseParenthesesPosition(str, position)<<std::endl;

  return 0;
}
