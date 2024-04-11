// LeetCode - 19 - Remove Nth Node from End of the List
// Given the head of a linked list, remove the nth node from the end of the list
// ex: head = [1,2,3,4,5], n = 2 => [1,2,3,5]
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

ListNode* removeNthFromEnd(ListNode* head, int n) {

  ListNode *slow = head;
  ListNode *fast = head;

  for(int i=0; i<n; i++) {
    if(!fast) {
      std::cout<<"List is short\n";
      return nullptr;
    }
    fast = fast->next;
  }

  if(fast == nullptr)
    return head->next;

  while(fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  ListNode *temp = slow->next;
  slow->next = slow->next->next;
  delete temp;
  temp = nullptr;

  return head;
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

  head = removeNthFromEnd(head, 2);
  display(head); // 1 -> 2 -> 3 -> 5

  return 0;
}
