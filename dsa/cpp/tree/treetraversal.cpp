// DSA - Tree - Basic Traversals (Inorder, Preorder, Postorder)
// Inorder - Order of Node traversal - Left - Root - Right
// Preorder - Order of Node traversal - Root - Left - Right
// Postorder - Order of Node traversal - Left - Right - Root
//
// Author: Thiru
//
// Time Complexity: O(n) - For all orders
// Space Complexity: O(1)

#include <iostream>

template <typename T>
class Node {
public:
  T m_data;
  Node *left;
  Node *right;
  Node(T data): m_data(data) {
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void printInorder(Node<T> *root) {
  if (!root)
    return;

  printInorder(root->left);
  std::cout<<root->m_data<<" ";
  printInorder(root->right);
}

template <typename T>
void printPreorder(Node<T> *root) {
  if (!root)
    return;

  std::cout<<root->m_data<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
}

template <typename T>
void printPostorder(Node<T> *root) {
  if (!root)
    return;

  printPostorder(root->left);
  printPostorder(root->right);
  std::cout<<root->m_data<<" ";
}

// main
int main()
{
  Node<int> *root = new Node<int>(1);
  root->left = new Node<int>(2);
  root->right = new Node<int>(3);

  root->left->left = new Node<int>(4);
  root->left->right = new Node<int>(5);

  root->right->left = new Node<int>(6);
  root->right->right = new Node<int>(7);

  std::cout<<"Inorder: ";
  printInorder(root);
  std::cout<<std::endl;

  std::cout<<"Preorder: ";
  printPreorder(root);
  std::cout<<std::endl;

  std::cout<<"Postorder: ";
  printPostorder(root);
  std::cout<<std::endl;

  return 0;
}
