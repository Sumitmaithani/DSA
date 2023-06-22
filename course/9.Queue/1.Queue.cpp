#include <iostream>
using namespace std;

class Node {
public:
  int size;
  int front;
  int rear;
  int *Q;
};

class Queue {
private:
  Node *q;

public:
  void create(int size);
  void enqueue(int x);
  int dequeue();
  void display();
};

void Queue::enqueue(int x) {
  if (q->rear == q->size - 1) {
    cout << "Queue is full" << endl;
  } else {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int Queue::dequeue() {
  int x = -1;
  if (q->front == q->rear) {
    cout << "Queue is empty" << endl;
  } else {
    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

void Queue::create(int size) {
  q = new Node;
  q->size = size;
  q->front = q->rear = -1;
  q->Q = new int[size];
}

void Queue::display() {
  for (int i = q->front + 1; i <= q->rear; i++) {
    cout << q->Q[i] << ' ';
  }
  cout << endl;
}

int main() {
  Queue q;
  q.create(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  cout << q.dequeue() << endl;
  q.display();

  return 0;
}