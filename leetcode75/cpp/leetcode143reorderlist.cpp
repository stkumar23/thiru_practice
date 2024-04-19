// LeetCode - 143 - Reorder List
// You are given the head of a singly linked-list.
// The list can be represented as: L0 -> L1 ->  ... -> Ln-1 -> Ln
// Reorder the list to be on the following form:
// L0 -> Ln -> L1 -> Ln-1 -> ...
// ex: head = [1,2,3,4] => [1,4,2,3]
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

void addNode(ListNode** head, int data) {
  ListNode *newNode = new ListNode();
  newNode->data = data;
  newNode->next = (*head);
  (*head) = newNode;
}

void displayList(ListNode* head) {
  ListNode *temp = head;
  std::cout<<"List contains: ";
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

ListNode* findMid(ListNode** head) {
  ListNode *slow = *head;
  ListNode *fast = *head;
  ListNode *prev = nullptr;

  while(fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;

  return slow;
}

void reverseList(ListNode** head) {
  ListNode * prev = nullptr;
  ListNode *curr = *head;
  while(curr) {
    ListNode *next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  (*head) = prev;
}

// Function to order the given linked list
// 1. Find the middle node of the list to halve it
// 2. Reverse the second half of the list
// 3. Merge these two lists

void reorderList(ListNode* head) {
  // Find the middle node to partition the given list
  ListNode *list2 = findMid(&head);

  // Reverse the second partition of the list
  reverseList(&list2);

  // Merge two lists
  ListNode *list1 = head;
  while(list1) {
    ListNode *l1_next = list1->next;
    ListNode *l2_next = list2->next;

    list1->next = list2;

    if (!l1_next)
      break;

    list2->next = l1_next;

    list1 = l1_next;
    list2 = l2_next;
  }
}

// main
int main()
{
  ListNode *head = nullptr;

  // populate linked list
  addNode(&head, 4);
  addNode(&head, 3);
  addNode(&head, 2);
  addNode(&head, 1);
  displayList(head);

  reorderList(head);
  displayList(head);

  return 0;
}
