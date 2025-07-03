// DSA - Tree - Binary Search Tree - Insertion
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
    Node(): data(0), left(nullptr), right(nullptr) {
    }
    Node(int d): data(d), left(nullptr), right(nullptr) {
    }
};


void insertBinaryTree(Node* root, int key) {
    Node* temp {nullptr};

    while (root) {
        temp = root;
        if (root->data == key) {
            std::cout<<key<<" is already found in the tree"<<std::endl;
            return;
        } else if (root->data < key) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    // in case the node with key value is not found, create and link it
    Node* newNode = new Node(key);
    if (temp) {
        if (temp->data < key) {
            temp->right = newNode;
            std::cout<<key<<" is added as the right child of node "<<temp->data<<std::endl;
        } else {
            temp->left = newNode;
            std::cout<<key<<" is added as the left child of node "<<temp->data<<std::endl;
        }
    }
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
    insertBinaryTree(root, 25);
    insertBinaryTree(root, 12);

    return 0;
}