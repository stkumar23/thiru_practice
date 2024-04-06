// LeetCode - 21 - Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.
// Merge two lists into one sorted list. Return the head of the merged list.
// ex: list1 = [1,2,4], list2 = [1,3,4] => [1,1,2,3,4,4]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>

class ListNode {
public:
  int val;
  ListNode* next;
};

void addNode(ListNode** head, int val) {
  ListNode *newNode = new ListNode();
  newNode->val = val;
  newNode->next = *head;

  *head = newNode;
}

void displayList(ListNode* head) {
  ListNode* temp = head;
  std::cout<<"List contains: ";
  while(temp) {
    std::cout<<temp->val<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (!list1 && !list2) {
    return nullptr;
  }

  if (!list1) {
    return list2;
  }

  if (!list2) {
    return list1;
  }

  ListNode* head = nullptr;
  if (list1->val < list2->val) {
    head = list1;
    list1 = list1->next;
  } else {
    head = list2;
    list2 = list2->next;
  }

  ListNode* curr = head;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      curr->next = list1;
      list1 = list1->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }

  if (!list1) {
    curr->next = list2;
  } else {
    curr->next = list1;
  }

  return head;
}

// main
int main()
{
  ListNode *list1 = nullptr;
  addNode(&list1, 4);
  addNode(&list1, 2);
  addNode(&list1, 1);
  displayList(list1);

  ListNode *list2 = nullptr;
  addNode(&list2, 4);
  addNode(&list2, 3);
  addNode(&list2, 1);
  displayList(list2);

  ListNode *mergedList = mergeTwoLists(list1, list2);
  displayList(mergedList);

  return 0;
}
