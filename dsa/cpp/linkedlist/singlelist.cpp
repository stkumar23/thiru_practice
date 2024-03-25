// DSA - Linked List - Singly Linked List
// Linked List Operations: InsertAtHead, InsertAtEnd, Search, Deletion,
//                       : Reverse, Display
//
// Author: Thiru
//
// Time Complexity: O(1) - InsertAtHead
//                : O(n) - InsertAtEnd
//                : O(n) - Display (Traverse)
//                : O(n) - Search (worst case)
//                : O(n) - Reverse
//                : O(n) - Deletion (worst case)
// Space Complexity: O(1) // For all operations


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
    head = nullptr;
  }

  void insertAtHead(T data) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(T data) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node<T> *temp = head;
    while(temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void search(T data) {
    Node<T> *temp = head;
    int index = -1;
    std::cout<<"Element "<<data;
    while (temp != nullptr) {
      index++;
      if (temp->data == data) {
        std::cout<<" is found at index "<<index<<std::endl;
        return;
      } else {
        temp = temp->next;
      }
    }
    std::cout<<" is not found"<<std::endl;
  }

  void display() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      std::cout<<temp->data<<" ";
      temp = temp->next;
    }
    std::cout<<"null"<<std::endl;
  }

  void reverse() {
    if (head == nullptr) {
      return;
    }

    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;

    while (head != nullptr) {
      next = head->next;
      head->next = prev;

      prev = head;
      head = next;
    }

    head = prev;
  }

  void deletion(T data) {
    if (head == nullptr) {
      std::cout<<"List is empty\n";
      return;
    }

    Node<T> *temp = nullptr;
    // delete head node
    if (head->data == data) {
      temp = head;
      head = head->next;
      delete temp;
    } else {
      Node<T> *curr = head;
      while(curr->next != nullptr) {
        if (curr->next->data == data) {
          temp = curr->next;
          curr->next = curr->next->next;
          delete temp;
          return;
        }
        curr = curr->next;
      }
    }
  }

};

int main()
{
  SinglyLinkedList<int> sll;

  // Singly Linked List operations
  sll.insertAtHead(10);
  sll.insertAtHead(20);
  sll.insertAtHead(30);
  sll.display(); // 30 -> 20 -> 10 -> null

  sll.search(30); // Found at index 0

  sll.insertAtEnd(5);
  sll.display(); // 30 -> 20 -> 10 -> 5 -> null

  sll.reverse(); // 5 -> 10 -> 20 -> 30 -> null
  sll.display();

  sll.deletion(30); // 5 -> 10 -> 20 -> null
  sll.display();

  return 0;
}
