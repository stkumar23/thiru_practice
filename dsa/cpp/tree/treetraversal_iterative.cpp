// DSA - Tree - Basic Traversals (Inorder, Preorder, Postorder)
// Tree traversals in iterative method
// Inorder - Order of Node traversal - Left - Root - Right
// Preorder - Order of Node traversal - Root - Left - Right
// Postorder - Order of Node traversal - Left - Right - Root
//
// Author: Thiru
//
// Time Complexity: O(n) - For all orders
// Space Complexity: O(h) - height of tree

#include <iostream>
#include <stack>

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
  std::stack<Node<T>*> stk;

  while (root || !stk.empty()) {
    if (root) {
      stk.push(root);
      root = root->left;
    } else {
      root = stk.top();
      stk.pop();
      std::cout<<root->m_data<<" ";
      root = root->right;
    }
  }
}

template <typename T>
void printPreorder(Node<T> *root) {
  std::stack<Node<T>*> stk;

  while (root || !stk.empty()) {
    if (root) {
      std::cout<<root->m_data<<" ";
      stk.push(root);
      root = root->left;
    } else {
      root = stk.top();
      stk.pop();
      root = root->right;
    }
  }
}

template <typename T>
void printPostorder(Node<T> *root) {
  std::stack<Node<T>*> stk;

  while (true) {
    while (root) {
      stk.push(root);
      stk.push(root);
      root = root->left;
    }

    if (stk.empty())
      return;

    root = stk.top();
    stk.pop();

    if (!stk.empty() && stk.top() == root) {
      root = root->right;
    } else {
      std::cout<<root->m_data<<" ";
      root = nullptr;
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
