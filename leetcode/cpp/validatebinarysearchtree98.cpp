// LeetCode - 98 - Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
// ex: root = [2,1,3] => true
// ex: root = [5,1,4,null,null,3,6] => false
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <stack>
#include <limits>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

bool isValidBST(TreeNode* root) {
    if (!root) {
        return true;
    }

    std::stack<TreeNode*> stk;
    long long preval = std::numeric_limits<long long>::min();

    while (root || !stk.empty()) {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();

        if (root->val <= preval) {
            return false;
        }

        preval = root->val;
        root = root->right;
    }

    return true;
}

int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);

    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);

    std::cout<<"Valid BST "<<std::boolalpha<<isValidBST(root)<<std::endl;

    return 0;
}