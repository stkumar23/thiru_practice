// Leetcode - 104 - Maximum Depth of Binary Tree
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the 
// longest path from the root node down to the farthest leaf node.
//
// ex: root = [3,9,20,null,null,15,7] => 3
// ex: root = [1,null,2] => 2
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(h) // h is the height of the binary tree

#include <iostream>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {
    }
};

int maxDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }

  std::queue<TreeNode*> queue;
  int height {0};
  int levelCount {0};
  TreeNode* curNode = nullptr;
  queue.emplace(root);

  while (!queue.empty()) {

    height++;
    levelCount = queue.size(); // number of nodes in each level

    while (levelCount--) {
        curNode = queue.front();
        if (curNode->left) {
            queue.emplace(curNode->left);
        }

        if (curNode->right) {
            queue.emplace(curNode->right);
        }
        queue.pop();
    }
  }

  return height;
}


int main() {

    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);

    // root->left->left = nullptr;
    // root->left->right = nullptr;

    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);

    std::cout<<"Maximum depth of the tree "<<maxDepth(root)<<std::endl;

    return 0;
}