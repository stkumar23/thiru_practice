// LeetCode - 771 - Jewels and Stones
// You're given strings jewels representing the types of stones that are jewels, 
// and stones representing the stones you have. Each character in stones is a type 
// of stone you have. You want to know how many of the stones you have are also 
// jewels. Letters are case sensitive.
//
// ex: jewels = "aA", stones = "aAAbbbb" => 3
// ex: jewels = "z", stones = "ZZ" => 0
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(m)

#include <iostream>
#include <string>
#include <unordered_set>

// Function to count jewels in stones
// Use a unordered_set to store the jewels
// Loop through the stones string and for each char, check if it is a jewel
// Count the jewels presence.
int countJewelsInStones (const std::string& j, const std::string& s) {
    std::unordered_set<char> jset = {j.begin(), j.end()};
    int count = 0;

    for (const char& ch : s) {
        if (jset.count(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    // std::string jewels = "z";
    // std::string stones = "ZZ";

    std::cout<<"Count " << countJewelsInStones(jewels, stones) << std::endl;

    return 0;
}