// DSA - Stack - Stack using Linked List
// Stack Operations: push, pop, isEmpty, peek
//
// Author: Thiru

#include <iostream>
#include <climits>

template <typename T>
class Stack {
public:
  T data;
  Stack* next;
};

// Function creates new node for Stack
template <typename T>
Stack<T>* createNode(T data) {
  Stack<T>* node = new Stack<T>();
  if (node) {
    node->data = data;
    node->next = nullptr;
    return node;
  }
  return nullptr;
}

// Function adds new node to the top of the Stack
template <typename T>
void push(Stack<T> **root, T data) {
  Stack<T> *newNode = createNode(data);
  if (newNode) {
    newNode->next = *root;
    *root = newNode;
  }
}

// Function to remove the top node from the Stack
template <typename T>
void pop(Stack<T> **root) {
  if (isEmpty(*root)) {
    std::cout<<"Stack is empty\n";
    return;
  }
  Stack<T>* temp = *root;
  *root = (*root)->next;
  delete temp;
}

// Function to print the contents of the Stack
template <typename T>
void print(Stack<T> *root) {
  while(root != nullptr) {
    std::cout<<root->data<<" ";
    root = root->next;
  }
  std::cout<<std::endl;
}

// Function to check whether the Stack is empty or not
template <typename T>
bool isEmpty(Stack<T> *root) {
  return !root;
}

// Function returns the top element data
template <typename T>
T peek(Stack<T> *root) {
  if (isEmpty(root)) {
    return INT_MIN;
  }
  return root->data;
}

// main
int main()
{
  Stack<int>* sk = nullptr;

  //add nodes
  push(&sk, 1);
  push(&sk, 2);
  push(&sk, 3);

  print(sk);
  std::cout<<"The top element is: "<<peek(sk)<<std::endl;

  // remove a node
  pop(&sk);
  std::cout<<"The top element is: "<<peek(sk)<<std::endl;

  return 0;
}
