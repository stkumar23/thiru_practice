// LeetCode - 938 - Range Sum of Binary Search Tree
// Given the root node of a binary search tree and two integers 
// low and high, return the sum of values of all nodes with a 
// value in the inclusive range [low, high].
// 
// ex: root = [10,5,15,3,7,null,18], low = 7, high = 15 => 32 (7+10+15)
// ex: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10 => 23 (6+7+10)
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(h) // height of the tree

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) {
        return 0;
    }

    // skip the left nodes
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // skip the right nodes
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(7);

    // root->right->left = nullptr;
    // root->right->right = new TreeNode(18);

    // int low {7};
    // int high {15};

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = nullptr;
    root->left->right->left = new TreeNode(6);
    root->left->right->right = nullptr;

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    int low {6};
    int high {10};
 
    std::cout<<"Sum range of BST "<<rangeSumBST(root, low, high)<<std::endl;

    return 0;
}