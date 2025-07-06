// LeetCode - 112 - Path sum
// Given the root of a binary tree and an integer targetSum, return true
// if the tree has a root-to-leaf path such that adding up all the values
// along the path equals targetSum.
//
// ex: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22 => true
// ex: root = [1,2,3], targetSum = 5 => false
// ex: root = [], targetSum = 0 => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <utility>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

//Recursive Function
bool hasPathSumRecursive(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    targetSum -= root->val;
    if (!root->left && !root->right && 0 == targetSum) {
        return true;
    }

    return hasPathSumRecursive(root->left, targetSum) || 
        hasPathSumRecursive(root->right, targetSum);
}

// using BFS
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    std::queue<std::pair<TreeNode*, int>> queue;
    queue.emplace(std::make_pair(root,root->val));
    while (!queue.empty())
    {
        auto [node, sum] = queue.front();
        queue.pop();

        // leaf node check
        if (!node->left && !node->right && sum == targetSum) {
            return true;
        }

        if (node->left) {
            queue.push(std::make_pair(node->left, sum+node->left->val));
        }
        if (node->right) {
            queue.push(std::make_pair(node->right, sum+node->right->val));
        }
    }
    return false;
}

int main() {
    int sum;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->right = nullptr;
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = nullptr;
    root->right->right->right = new TreeNode(1);

    sum = 22;

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    // sum = 5;

    std::cout<<"Path Sum "<<std::boolalpha<<hasPathSum(root, sum)<<std::endl;
    return 0;
}
