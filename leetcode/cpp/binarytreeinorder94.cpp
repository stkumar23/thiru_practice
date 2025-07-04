// LeetCode - 94 - Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// 
// ex: root = [1, null, 2 ,3] => [1,3,2]
// ex: root = [1,2,3,4,5,null,8,null,null,6,7,9] => [4,2,6,5,7,1,3,9,8]
// ex: root = [] => []
// ex: root = [1] => [1]
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <vector>
#include <stack>

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d): data(d), left(nullptr), right(nullptr) {
    }
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stk;
    std::vector<int> vec{};

    while(root || !stk.empty()) {
        if (root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            vec.push_back(root->data);
            root = root->right;
        }
    }

    return vec;
}

int main() {
    // TreeNode *root = new TreeNode(1);
    // root->left = nullptr;
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->right = nullptr;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right->left = nullptr;
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = nullptr;

    std::vector<int> res = inorderTraversal(root);

    for (const auto& r: res) {
        std::cout<<r<<" ";
    }
    std::cout<<std::endl;

    return 0;
}