// DSA - Linked List - Singly Linked List - Find middle node
// Using Floyd's Cycle-Finding Algorithm, find the middle nodee of linked list
// When the nodes are even, find the second middle node
// Ex: [1,2,3,4,5] => 3
// Ex: [1,2,3,4,5,6] => 4
//
// Author: Thiru
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>

template <typename T>
class Node {
public:
  T data;
  Node* next;
};


template <typename T>
class SinglyLinkedList {
  Node<T> *head;
public:
  SinglyLinkedList() : head(nullptr) {
  }

  ~SinglyLinkedList() {
  }

  void insertAtHead(T data) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = head;

    if (head == nullptr) {
      head = newNode;
    }

    head = newNode;
  }

  T findMiddle() {
    Node<T> *sp = head;
    Node<T> *fp = head;

    while (sp && fp && fp->next) {
      sp = sp->next;
      fp = fp->next->next;
    }
    return sp->data;
  }

};

int main ()
{
  SinglyLinkedList<int> sll;
  sll.insertAtHead(6);
  sll.insertAtHead(5);
  sll.insertAtHead(4);
  sll.insertAtHead(3);
  sll.insertAtHead(2);
  sll.insertAtHead(1);

  // 1 -> 2 -> 3 -> 4 -> 5 -> 6
  std::cout<<"The middle node is "<<sll.findMiddle()<<std::endl;
}
