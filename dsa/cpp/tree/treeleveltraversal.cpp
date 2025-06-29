// DSA - Tree - Level Traversal
// Tree Level traversal in iterative method
// Level order - Order of traversal - Root - Left - Right - Child of Left node - Child of Right node
//
// Author: Thiru
//
// Time Complexity: O(n)
// Space Complexity: O(h) - height of tree

#include <iostream>
#include <queue>

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
void printLevelOrder(Node<T> *root) {
  std::queue<Node<T>*> queue;

  if (!root) {
    return;
  }

  std::cout<<root->m_data<<" ";
  queue.emplace(root);

  while (!queue.empty()) {

    root = queue.front();
    queue.pop();

    if (root->left) {
      std::cout<<root->left->m_data<<" ";
      queue.emplace(root->left);
    }

    if (root->right) {
      std::cout<<root->right->m_data<<" ";
      queue.emplace(root->right);
    }
  }
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

  std::cout<<"Level Order: ";
  printLevelOrder(root);
  std::cout<<std::endl;

  return 0;
}
