// DSA - Queue - Queue using Linked List
// Stack Operations: enqueue, dequeue
// Use two pointers front and rear
//
// Author: Thiru

#include <iostream>
#include <climits>

template <typename T>
class Queue {
public:
    T data;
    Queue *next;
};

// Function to create new queue node
template <typename T>
Queue<T>* createNode(T data) {
  Queue<T> *newNode = new Queue<T>();
  if (newNode) {
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
  }
  return nullptr;
}

// Function to add new node in the queue
// Insert the new node at rear
// In case queue is empty, set front and rear with new node
template <typename T>
void enqueue(Queue<T>** front, Queue<T>** rear, T data) {
  Queue<T> *newNode = createNode(data);
  if (*rear == nullptr) {
    *front = *rear = newNode;
    return;
  }
  (*rear)->next = newNode;
  *rear = newNode;
}

// Function to remove a node from queue
template <typename T>
void dequeue(Queue<T>** front, Queue<T>** rear) {
  if (*front == nullptr) {
    std::cout<<"Queue is Empty"<<std::endl;
    return;
  }

  Queue<T> *temp = (*front);
  *front = (*front)->next;

  if (*front == nullptr)
    *rear = nullptr;

  std::cout<<"Dequeued data "<<temp->data<<std::endl;
  delete temp;
  temp = nullptr;
}

// Function to print the contents of queue
template <typename T>
void print(Queue<T> *root) {
  while(root) {
    std::cout<<root->data<<" ";
    root = root->next;
  }
  std::cout<<std::endl;
}

// main
int main()
{
  Queue<int> *front = nullptr;
  Queue<int> *rear = nullptr;

  enqueue(&front, &rear, 1);
  enqueue(&front, &rear, 2);
  enqueue(&front, &rear, 3);
  enqueue(&front, &rear, 4);

  print(front);

  dequeue(&front, &rear);
  print(front);

  return 0;
}
