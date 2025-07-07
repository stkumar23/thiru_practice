// LeetCode - 404 - Sum of Left Leaves
// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children. A left leaf is a leaf that is the
// left child of another node.
//
// ex: root = [3,9,20,null,null,15,7] => 24 (9+15)
// ex: root = [1] => 0
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

// using BFS
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 0;
    }

    int sum{0};
    std::queue<TreeNode*> queue;
    queue.emplace(root);
    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();

        if (node->left) {
            queue.push(node->left);
        }
        if (node->right) {
            queue.push(node->right);
        }

        // leaf node check
        if (node->left && !node->left->left && !node->left->right) {
            sum += node->left->val;
        }
    }
    return sum;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->left->left = nullptr;
    root->left->right = nullptr;

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // TreeNode *root = new TreeNode(1);

    std::cout<<"Path Sum "<<sumOfLeftLeaves(root)<<std::endl;
    return 0;
}
