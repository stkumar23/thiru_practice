// DSA - Tree - Height and Number of Nodes (count)
//
// Author: Thiru
//
// Time Complexity: O(n)
// Space Complexity: O(h) - height of tree

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
int getTreeHeight(Node<T> *root) {
  if (!root) {
    return -1;
  }

  if (root) {
    int x = getTreeHeight(root->left);
    int y = getTreeHeight(root->right);
    return std::max(x, y) + 1;
  }
  return 0;
}

template <typename T>
int getNodeCount(Node<T> *root) {

  if (root) {
    int x = getNodeCount(root->left);
    int y = getNodeCount(root->right);
    return x+y+1;
  }
  return 0;
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

  std::cout<<"Height of the tree is: " << getTreeHeight(root) <<std::endl;

  std::cout<<"Number of nodes in the tree are: " << getNodeCount(root) <<std::endl;

  return 0;
}
