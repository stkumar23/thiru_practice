// LeetCode - 394 - Decode String
// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside 
// the square brackets is being repeated exactly k times. Note that k is
// guaranteed to be a positive integer.
//
// ex: s = "3[a]2[bc]" => "aaabcbc"
// ex: s = "3[a2[c]]" => "accaccacc"
// ex: s = "2[abc]3[cd]ef" => "abcabccdcdcdef"
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <string>
#include <stack>
#include <utility>

// Function to format (repeat) the given string n times

std::string formatString(const std::string& s, const int& n) {
    std::string str;
    for (int i=0; i<n; i++) {
        str += s;
    }
    return str;
}

// Function to decode the given string
// Read the digit, char one by one.
// Use a stack to place the current string and the repeat times
// On ']' format the current string the repeat times from the stack

std::string decodeString(const std::string& s) {
    std::stack<std::pair<std::string, int>> stk;
    std::string curStr;
    int curNum = 0;

    for (const char& c: s) {
        if (std::isdigit(c)) {
            curNum = curNum * 10 + c - '0';
        } else if (c == '[') {
            stk.emplace(std::make_pair(curStr, curNum));
            curStr = "";
            curNum = 0;
        } else if (c == ']') {
            const auto [prevStr, n] = stk.top();
            stk.pop();
            curStr = prevStr + formatString(curStr, n);
        } else {
            curStr += c;
        }
    }
    return curStr;
}

int main() {
    //std::string s("3[a]2[bc]");
    //std::string s("3[a2[c]]");
    std::string s("2[abc]3[cd]ef");

    std::cout<< "Decoded String " << decodeString(s) << std::endl;

    return 0;
}