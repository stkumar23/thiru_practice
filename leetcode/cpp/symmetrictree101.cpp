// LeetCode - 101 - Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).
// 
// ex: root = [1,2,2,3,4,4,3] => true
// ex: root = [1,2,2,null,3,null,3] => false
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

// Use level order traversal and compare the nodes
bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }

    std::queue<TreeNode*> queue;
    queue.push(root->left);
    queue.push(root->right);

    while (!queue.empty()) {
        TreeNode* node1 = queue.front();
        queue.pop();
        TreeNode* node2 = queue.front();
        queue.pop();

        // Both the nodes are null, so symmetric
        if (!node1 && !node2) {
            continue;
        }

        // Any one of the node is NULL, or having different values
        if (!node1 || !node2 || (node1->val != node2->val)) {
            return false;
        }

    // Enqueue children for symmetric comparison in the order of 
    // node 1 - left and node 2 - right
    // node 1 - right and node 1 - left
        queue.push(node1->left);
        queue.push(node2->right);
        queue.push(node1->right);
        queue.push(node2->left);
    }

    return true;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = nullptr;
    // root->left->right = new TreeNode(3);
    // root->right->left = nullptr;
    // root->right->right = new TreeNode(3);
    
    std::cout<<"Symmetric Tree "<<std::boolalpha<<isSymmetric(root)<<std::endl;

    return 0;
}