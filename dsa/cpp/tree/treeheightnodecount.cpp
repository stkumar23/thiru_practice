// DSA - Tree - Height and Number of Nodes (count)
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
int getTreeHeight(Node<T> *root) {
  if (!root) {
    return 0;
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

template <typename T>
int getNodeHeightIterative(Node<T> *root) {
  if (!root) {
    return 0;
  }

  std::queue<Node<T>*> queue;
  int height {0};
  int levelCount {0};
  Node<T>* curNode = nullptr;
  queue.emplace(root);

  while (!queue.empty()) {

    height++;
    levelCount = queue.size(); // number of nodes in each level

    while (levelCount--) {
        curNode = queue.front();
        if (curNode->left) {
            queue.emplace(curNode->left);
        }

        if (curNode->right) {
            queue.emplace(curNode->right);
        }
        queue.pop();
    }
  }

  return height;
}


template <typename T>
int getNodeCountIterative(Node<T> *root) {
  if (!root) {
    return 0;
  }

  std::queue<Node<T>*> queue;
  int count {0};
  queue.emplace(root);

  while (!queue.empty()) {

    root = queue.front();
    queue.pop();
    count++;

    if (root->left) {
        queue.emplace(root->left);
    }

    if (root->right) {
        queue.emplace(root->right);
    }
  }

  return count;
}

template <typename T>
int getLeafNodeCountIterative(Node<T> *root) {
  if (!root) {
    return 0;
  }

  std::queue<Node<T>*> queue;
  int count {0};
  queue.emplace(root);

  while (!queue.empty()) {

    root = queue.front();
    queue.pop();

    if (root->left) {
        queue.emplace(root->left);
    }

    if (root->right) {
        queue.emplace(root->right);
    }

    // Increment the count in case no left and right nodes for a node
    if (!root->left && !root->right) {
      count++;
    }

  }

  return count;
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
  std::cout<<"Height of the tree is: " << getNodeHeightIterative(root) <<std::endl;

  std::cout<<"Number of nodes in the tree are: " << getNodeCount(root) <<std::endl;
  std::cout<<"Number of nodes in the tree are: " << getNodeCountIterative(root) <<std::endl;

  std::cout<<"Number of leaf nodes in the tree are: " << getLeafNodeCountIterative(root) <<std::endl;

  return 0;
}
