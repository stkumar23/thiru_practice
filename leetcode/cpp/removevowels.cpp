// LeetCode - 1119 - Remove vowels from a string
// Given a string s, remove the vowels from it and return the new string.
// String contains all lowercase letters
//
// ex: address = "leetcode" => "ltcd"
// ex: address = "aeiou" => ""
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to remove vowels from a string
// Use the vowels list and replace the matching char 
// in a string with empty char. Decrement the size of string

void removeVowels(std::string& str) {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < str.size(); i++) {
        if (std::find(vowels.begin(), vowels.end(), str[i]) != vowels.end()) {
            str.replace (i, 1, "");
            i -= 1;
        }
    }
}

int main() {
    std::string str("leetcode");
    removeVowels(str);
    std::cout<<"String without vowels: " << str << std::endl;

    return 0;
}