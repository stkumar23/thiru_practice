// LeetCode - 23 - Merge k sorted Lits
// Given an array of k linked lists, each linked list is sorted in ascending
// order. Merge all the linked lists into one sorted linked list and return it.
// ex: lists = [[1,4,5],[1,3,4],[2,6]] => [1,1,2,3,4,4,5,6]
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>

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

// Function to merge k sorted lists
// Invoke mergeTwoLists with each two lists from the container until the
// container size is one
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
  int size = lists.size();
  if (size == 0)
    return nullptr;

  while (size > 1) {
    for (int i = 0; i < size/2; i++) {
      lists[i] = mergeTwoLists(lists[i], lists[size-i-1]);
    }
    size = (size + 1) / 2;
  }

  return lists.front();
}

// main
int main()
{
  ListNode *list1 = nullptr;
  addNode(&list1, 5);
  addNode(&list1, 4);
  addNode(&list1, 1);

  ListNode *list2 = nullptr;
  addNode(&list2, 4);
  addNode(&list2, 3);
  addNode(&list2, 1);

  ListNode *list3 = nullptr;
  addNode(&list3, 6);
  addNode(&list3, 2);

  std::vector<ListNode*> v;
  v.push_back(list1);
  v.push_back(list2);
  v.push_back(list3);

  ListNode *mergedList = mergeKLists(v);
  displayList(mergedList);

  return 0;
}
