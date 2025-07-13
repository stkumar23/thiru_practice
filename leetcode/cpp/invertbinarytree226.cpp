// LeetCode - 226 - Invert Binary Tree
// Given the root of a binary tree, invert the tree, and return its root.
//
// ex: root = [4,2,7,1,3,6,9] => [4,7,2,9,6,3,1]
// ex: root = [2,1,3] => [2,3,1]
// ex: root = [] => []
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

// Use BFS
TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* curnode = queue.front();
        queue.pop();

        // Both the nodes are null, so symmetric
        std::swap (curnode->left, curnode->right);

        if (curnode->left) {
            queue.push(curnode->left);
        }
        if (curnode->right) {
            queue.push(curnode->right);
        }
    }

    return root;
}

void printPreorder(TreeNode *root) {
  if (!root)
    return;

  std::cout<<root->val<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
}


int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // TreeNode *root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);

    TreeNode *res = invertTree(root);
    printPreorder(res);
    std::cout<<std::endl;

    return 0;
}