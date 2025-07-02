// DSA - Tree - Binary Search Tree
// A binary search tree (BST) is a hierarchical data structure where each node 
// has at most two children, typically referred to as the left and right child. 
// The key property of a BST is that for every node, all nodes in its left
// subtree have values less than the node's value, and all nodes in its right 
// subtree have values greater than the node's value.
//
// Author: Thiru
//
// Time Complexity: O(logn)
// Space Complexity: O(1)

#include <iostream>

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d): data(d), left(nullptr), right(nullptr) {
    }
};

bool searchBinaryTreeRecursive(Node* root, int key) {
    if (!root) {
        return false;
    }

    if (root->data == key) {
        return true;
    } else if (root->data < key) {
        return searchBinaryTreeRecursive(root->right, key);
    } else {
        return searchBinaryTreeRecursive(root->left, key);
    }
}

bool searchBinaryTree(Node* root, int key) {
    while (root) {
        if (root->data == key) {
            return true;
        } else if (root->data < key) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return false;
}

int main() {
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);

    root->left->left = new Node(10);
    root->left->right = new Node(25);

    root->right->left = new Node(35);
    root->right->right = new Node(50);

    // Using non-recursive function
    std::cout<<"Key found in the binary tree "<<std::boolalpha<<searchBinaryTree(root, 25)<<std::endl;
    std::cout<<"Key found in the binary tree "<<std::boolalpha<<searchBinaryTree(root, 12)<<std::endl;

    // Using recursive function
    std::cout<<"Key found in the binary tree "<<std::boolalpha<<searchBinaryTreeRecursive(root, 25)<<std::endl;
    std::cout<<"Key found in the binary tree "<<std::boolalpha<<searchBinaryTreeRecursive(root, 12)<<std::endl;

    return 0;
}