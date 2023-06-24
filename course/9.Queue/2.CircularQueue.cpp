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
  if ((q->rear + 1) % q->size == q->front) {
    cout << "Queue is full" << endl;
  } else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

int Queue::dequeue() {
  int x = -1;
  if (q->front == q->rear) {
    cout << "Queue is empty" << endl;
  } else {
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

void Queue::create(int size) {
  q = new Node;
  q->size = size;
  q->front = q->rear = 0;
  q->Q = new int[size];
}

void Queue::display() {
  int i = q->front + 1;

  do {
    cout << q->Q[i] << ' ';
    i = (i + 1) % q->size;
  } while (i != (q->rear + 1) % q->size);
  cout << endl;
}

int main() {
  Queue q;
  q.create(5);
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