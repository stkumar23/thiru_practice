// LeetCode - 206 - Reverse Linked List
// Given the head of a singly linked list, reverse the list and return the
// reversed list.
// ex: head = [1,2,3,4,5] => [5,4,3,2,1]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>

class ListNode {
public:
  int data;
  ListNode* next;
};

void insertAtHead(ListNode** head, int data) {
  ListNode *newNode = new ListNode();
  newNode->data = data;
  newNode->next = (*head);
  (*head) = newNode;
}

void display(ListNode* head) {
  ListNode *temp = head;
  while (temp != nullptr) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

ListNode* reverseList(ListNode* head) {
  ListNode *prev = nullptr;

  while (head) {
    ListNode *next = head->next;
    head->next = prev;

    prev = head;
    head = next;
  }
  return prev;
}

// main
int main ()
{
  ListNode *head = nullptr;

  insertAtHead(&head, 5);
  insertAtHead(&head, 4);
  insertAtHead(&head, 3);
  insertAtHead(&head, 2);
  insertAtHead(&head, 1);

  display(head); // 1 -> 2 -> 3 -> 4 -> 5

  head = reverseList(head);
  display(head); // 5 -> 4 -> 3 -> 2 -> 1

  return 0;
}
