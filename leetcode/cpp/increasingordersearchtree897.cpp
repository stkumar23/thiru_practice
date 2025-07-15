// LeetCode - 897 - Increasing Order Search Tree
// Given the root of a binary search tree, rearrange the tree in in-order 
// so that the leftmost node in the tree is now the root of the tree, and 
// every node has no left child and only one right child.
//
// ex: root = [5,3,6,2,4,null,8,1,null,null,null,7,9] => 
//          [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// ex: root = [5,1,7] => [1,null,5,null,7]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <stack>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

// using BFS
// Flatten the tree into linked list form
// no left child, only right child
TreeNode* increasingBST(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    // temp head node
    TreeNode *tmpHead = new TreeNode(0);
    std::stack<TreeNode*> stk;
    TreeNode *newNode = tmpHead;
    TreeNode *curNode = root;

    while (curNode || !stk.empty()) {

        // traverse to left most node
        while (curNode) {
            stk.push(curNode);
            curNode = curNode->left;
        }

        curNode = stk.top();
        stk.pop();

        newNode->right = curNode;
        curNode->left = nullptr;
        newNode = curNode;

        curNode = curNode->right;
    }

    return tmpHead->right;
}

void printInorder(TreeNode *root) {
  if (!root)
    return;

  printInorder(root->left);
  std::cout<<root->val<<" ";
  printInorder(root->right);
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = nullptr;

    root->right->left = nullptr;
    root->right->right = new TreeNode(8);

    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(7);

    TreeNode *res = increasingBST(root);
    printInorder(res);
    std::cout<<std::endl;

    return 0;
}