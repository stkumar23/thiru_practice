// LeetCode - 145 - Binary Tree Postorder Traversal
// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// 
// ex: root = [1, null, 2 ,3] => [3,2,1]
// ex: root = [1,2,3,4,5,null,8,null,null,6,7,9] => [4,6,7,5,2,9,8,3,1]
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
#include <algorithm>

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d): data(d), left(nullptr), right(nullptr) {
    }
};

std::vector<int> postorderTraversal(TreeNode* root) {
    if (!root) {
        return {};
    }

    std::stack<TreeNode*> stk;
    std::vector<int> vec{};
    stk.push(root);

    while(!stk.empty()) {
        root = stk.top();
        stk.pop();
        vec.push_back(root->data);
        if (root->left) {
            stk.push(root->left);
        }

        if (root->right) {
            stk.push(root->right);
        }
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int main() {
    TreeNode *root = new TreeNode(1);
    // root->left = nullptr;
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->right = nullptr;

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

    std::vector<int> res = postorderTraversal(root);

    for (const auto& r: res) {
        std::cout<<r<<" ";
    }
    std::cout<<std::endl;

    return 0;
}