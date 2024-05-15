// LeetCode - 49 - Group Anagrams
// Given an array of strings strs, group the anagrams together.
// ex: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//    output = [["bat"], ["nat","tan"], ["ate", "eat","tea"]]
//
// Author: Thiru
//
// Time complexity: O(mnlogn)
// Space complexity: O(mn)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


// Function to group the anagrams
// Sort the string and use it as key to find the group
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  std::vector<std::vector<std::string>> res;
  int size = strs.size();
  if (size == 0)
    return res;

  std::unordered_map<std::string, std::vector<std::string>> umap{};

  for (auto& str: strs) {
    std::string key = str;
    std::sort(key.begin(), key.end());
    umap[key].emplace_back(str);
  }

  for (auto& pair: umap) {
    res.emplace_back(pair.second);
  }

  return res;
}

int main()
{
  std::vector<std::string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> res = groupAnagrams(v);

  std::cout<<"output: "<<std::endl;
  for (const auto& strs: res) {
    for (const auto& s: strs) {
      std::cout<<s<<" ";
    }
    std::cout<<std::endl;
  }
  return 0;
}
