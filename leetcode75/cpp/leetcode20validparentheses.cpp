// LeetCode - 20 - Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[', ']'
// Determine if the input string is valid.
// ex: s = "()" => true
// ex: s = "(]" => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

bool isValid(const std::string& s) {
  std::stack<char> st;
  std::unordered_map<char, char> m = {
              {')', '('},
              {'}', '{'},
              {']', '['}
              };

  for (const auto& c: s) {
    if (m.find(c) != m.end()) {
      if (st.empty()) {
        return false;
      }
      if (m[c] !=st.top()) {
        return false;
      }
      st.pop();
    } else {
      st.push(c);
    }
  }

  return st.empty();
}

// main
int main()
{
  std::string s = "()";
  //std::string s = "(]";

  std::cout<<"Valid Parentheses "<<std::boolalpha<<isValid(s)<<std::endl;
  return 0;
}
