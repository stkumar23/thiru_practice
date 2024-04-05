// DSA - Linked List - Doubly Linked List
// Linked List Operations: InsertAtHead, InsertAtEnd, Display
//                       : DisplayReverse, Search
//                       : DeletionAtHead, DeleteANode, DeletionAtEnd
//
// Author: Thiru
//
// Time Complexity: O(1) - InsertAtHead
//                : O(n) - InsertAtEnd
//                : O(n) - Display (Traverse)
//                : O(n) - Display (reverse order)
//                : O(1) - DeletionAtHead
//                : O(n) - DeleteANode
//                : O(n) - DeletionAtEnd
//                : O(n) - Search
// Space Complexity: O(1) // For all operations

#include <iostream>

template <typename T>
class Node {
public:
  T data;
  Node* prev;
  Node* next;
};

template <typename T>
class DoublyLinkedList {
  Node<T> *head;
public:
  DoublyLinkedList() : head(nullptr) {
  }

  ~DoublyLinkedList() {
    Node<T> *currNode = head;
    while (!currNode) {
      head = currNode->next;
      delete currNode;
      currNode = head;
    }
    head = currNode = nullptr;
  }

  void insertAtHead(T data) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    newNode->next = head;
    newNode->prev = nullptr;

    if (head) {
      head->prev = newNode;
    }

    head = newNode;
  }

  void insertAtEnd(T data) {
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
      head = newNode;
      return;
    }

    Node<T> *tail = head;
    while(tail->next) {
      tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
  }

  void display() {
    Node<T> *temp = head;
    std::cout<<"Doubly Linked List contains: ";
    while(temp) {
      std::cout<<temp->data<<" ";
      temp = temp->next;
    }
    std::cout<<std::endl;
  }

  void displayReverse() {
    Node<T> *tail = head;
    std::cout<<"List in reverse order: ";
    while(tail->next) {
      tail = tail->next;
    }

    while(tail) {
      std::cout<<tail->data<<" ";
      tail = tail->prev;
    }
    std::cout<<std::endl;
  }

  void search(T data) {
    Node<T> *temp = head;
    while(temp) {
      if (temp->data == data) {
        std::cout << "Node with data " << data << " is found" << std::endl;
        return;
      }
      temp = temp->next;
    }
    std::cout << "Node with data " << data << " is not found" << std::endl;
  }

  void deletionAtHead() {
    if (!head)
      return;

    if (!head->next) {
      delete head;
      head = nullptr;
    } else {
      Node<T> *temp = head;
      head = head->next;
      head->prev = nullptr;
      delete temp;
    }
  }

  void deletionAtEnd() {
    if (!head)
      return;

    if (!head->next) {
      delete head;
      head = nullptr;
      return;
    }

    Node<T> *temp = head;
    while(temp->next) {
      temp = temp->next;
    }

    Node<T> *prev = temp->prev;
    prev->next = nullptr;
    delete temp;
  }

  void deleteANode(T data) {
    if (!head)
      return;

    if (head->data == data) {
      deletionAtHead();
    } else {
      Node<T> *temp = head;
      while(temp) {
        if (temp->data == data) {
          Node<T> *prev = temp->prev;
          Node<T> *next = temp->next;

          prev->next = next;
          if (next) {
            next->prev = prev;
          }
          delete temp;
          return;
        }
        temp = temp->next;
      }
    }
  }
};

int main()
{
  DoublyLinkedList<int> dll;

  // Doubly Linked List Operations
  dll.insertAtHead(5);
  dll.insertAtHead(4);
  dll.insertAtHead(3);
  dll.insertAtHead(2);
  dll.insertAtHead(1);
  dll.display();

  dll.insertAtEnd(6);
  dll.displayReverse();

  dll.search(3);

  dll.deletionAtHead();
  dll.display();

  dll.deletionAtEnd();
  dll.display();

  dll.deleteANode(4);
  dll.display();
  dll.displayReverse();

  return 0;
}
