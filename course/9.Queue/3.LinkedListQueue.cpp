#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
} *front = NULL, *rear = NULL;

class Queue {

public:
  void enqueue(int x);
  int dequeue();
  void display();
};

void Queue::enqueue(int x) {
  Node *t;
  t = new Node;
  if (t == NULL) {
    cout << "Queue is full" << endl;
  } else {
    t->data = x;
    t->next = NULL;
    if (front == NULL) {
      front = rear = t;
    } else {
      rear->next = t;
      rear = t;
    }
  }
}

int Queue::dequeue() {
  int x = -1;
  Node *t;
  if (front == NULL) {
    cout << "Queue is empty" << endl;
  } else {
    x = front->data;
    t = front;
    front = front->next;
    delete t;
  }
  return x;
}

void Queue::display() {
  Node *p = front;
  while (p) {
    cout << p->data << ' ';
    p = p->next;
  }
  cout << endl;
}

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.display();
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  q.enqueue(5);
  q.enqueue(6);
  q.enqueue(7);
  q.display();

  return 0;
}