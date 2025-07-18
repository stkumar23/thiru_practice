// LeetCode - 102 - Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal 
// of its nodes' values. (i.e., from left to right, level by level).
//
// ex: root = [3,9,20,null,null,15,7] => [[3],[9,20],[15,7]]
// ex: root = [1] => [[1]]
// ex: root = [] => []
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result{};

    std::queue<TreeNode*> queue;

    if (!root) {
        return result;
    }

    std::vector<int> levelvec{};
    levelvec.push_back(root->val);
    result.push_back(levelvec);
    queue.emplace(root);

    while (!queue.empty()) {

        root = queue.front();
        queue.pop();

        levelvec.clear();
        if (root->left) {
            levelvec.push_back(root->left->val);
            queue.emplace(root->left);
        }

        if (root->right) {
            levelvec.push_back(root->right->val);
            queue.emplace(root->right);
        }
        if (levelvec.size()) {
            result.push_back(levelvec);
        }
    }

    return result;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    //TreeNode *root = new TreeNode(1);

    std::vector<std::vector<int>> res = levelOrder(root);

    for (const auto& r: res) {
        for (const auto& e: r) {
            std::cout<<e<<" ";
        }
        std::cout<<", ";
    }
    std::cout<<std::endl;

    return 0;
}