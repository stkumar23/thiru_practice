// LeetCode - 141 - Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has
// a cycle in it.
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

void insertAtHead(ListNode **head, ListNode **tail,
                  int data, bool loop = false) {
  ListNode *newNode = new ListNode();
  newNode->data = data;
  newNode->next =(*head);

  if ((*head) == nullptr) {
    (*head) = newNode;
    (*tail) = newNode;
  }

  // tail node is connected to head (first node) to form a loop
  if (loop)
    (*tail)->next = newNode;

  (*head) = newNode;
}

bool hasCycle(ListNode* head) {

  if (!head) {
    return false;
  }

  ListNode *sp = head;
  ListNode *fp = head->next;

  while(fp && fp->next) {
    if (sp == fp)
      return true;

    sp = sp->next;
    fp = fp->next->next;
  }
  return false;
}

int main()
{
  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  insertAtHead(&head, &tail, 1);
  insertAtHead(&head, &tail, 2);
  insertAtHead(&head, &tail, 3);
  insertAtHead(&head, &tail, 4);
  insertAtHead(&head, &tail, 5, true);
  std::cout<< "List has cycle? : " << std::boolalpha
                                  << hasCycle(head)<<std::endl;

  return 0;
}
