// Program to check whether the give string is permutation palindrome or not
// Ex: "kayak" => true
// Ex: "kakay" => true
// Ex: "hello" => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>
#include <unordered_set>

// Function to check whether the word is permutation palindrome or not
// Create a hash and add the char into it, if it is not found
// Remove the char from the hash, if it is already found
// Iterate through the string and for each char repeat this step
// The hash size should be less than or equal to one at the end

bool isWordPermutationPalindrome(const std::string& str) {
  std::unordered_set<char> uset;

  for (char c: str) {
    if (uset.find(c) == uset.end()) {
      uset.insert(c);
    } else {
      uset.erase(c);
    }
  }

  return uset.size() <= 1;
}


// main
int main()
{
  std::string word1 = "hello";
  std::string word2 = "kayak";
  std::string word3 = "kakay";

  std::cout<<"is "<<word1<<" permutation palindrome? "<<std::boolalpha
                  <<isWordPermutationPalindrome(word1)<<std::endl;
  std::cout<<"is "<<word2<<" permutation palindrome? "
                  <<isWordPermutationPalindrome(word2)<<std::endl;
  std::cout<<"is "<<word3<<" permutation palindrome? "
                  <<isWordPermutationPalindrome(word3)<<std::endl;

  return 0;
}
