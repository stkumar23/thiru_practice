// DSA - Linked List - Singly Linked List - Detect Loop
// Find whether the list has a cycle (loop) or not
// Using Floyd's Cycle-Finding Algorithm
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
  Node<T> *tail;
public:
  SinglyLinkedList() : head(nullptr), tail(nullptr) {
  }

  ~SinglyLinkedList() {
  }

  void insertAtHead(T data, bool lastNode = false) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = head;

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    }

    // tail node is connected head (first node) to form a loop
    if (lastNode)
      tail->next = newNode;

    head = newNode;
  }

  void detectLoop() {
    Node<T> *sp = head;
    Node<T> *fp = head;

    while (sp && fp && fp->next) {
      sp = sp->next;
      fp = fp->next->next;

      if (sp == fp) {
        std::cout<<"Loop is detected\n";
        return;
      }
    }
    std::cout<<"Loop is not detected\n";
  }

};

int main ()
{
  SinglyLinkedList<int> sll;

  // Singly Linked List operations
  sll.insertAtHead(10);
  sll.insertAtHead(20);
  sll.insertAtHead(30);
  sll.insertAtHead(40);
  sll.insertAtHead(50, true); // remove this bool flag to test no cycle
  sll.detectLoop(); // 10 -> 50 -> 40 -> 30 -> 20 -> 10
}
