// LeetCode - 804 - Unique Morse Code Words
// Given an array of strings words where each word can be written as a 
// concatenation of the Morse code of each letter.
// Return the number of different transformations among all words we have.
// String contains all lowercase letters.
//
// ex: words = ["a"] => 1
// ex: words = ["gin","zen","gig","msg"] => 2
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(m)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

// Function to find unique morse code representations
// The morse code for each letter is given.
// Loop through each word and transform the word into morse code form
// Add this form into a set. Return the set size
int uniqueMorseRepresentations(const std::vector<std::string>& words) {

    // morse code for each letter. a to z
    std::vector<std::string> morseCode = {".-","-...","-.-.","-..",".","..-."
        ,"--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
        ".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    std::unordered_set<std::string> transformation;

    for (const std::string& word : words) {
        std::string t;
        for (const char& ch : word) {
            t += morseCode[ch - 'a'];
        }
        transformation.insert(t);
    }

    return transformation.size();
}

int main() {

    //std::vector<std::string> words{"a"};
    std::vector<std::string> words{"gin","zen","gig","msg"};
    std::cout<< "Transformations " << uniqueMorseRepresentations(words) << std::endl;
    return 0;
}