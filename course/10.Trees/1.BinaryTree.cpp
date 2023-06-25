#include <iostream>
using namespace std;

class Node {
public:
  Node *lchild;
  int data;
  Node *rchild;
};

class Queue {
private:
  int size;
  int front;
  int rear;
  Node **Q;

public:
  void create(int size);
  void enqueue(Node *x);
  Node *dequeue();
  int isEmpty();
};

void Queue::create(int size) {
  this->size = size;
  front = -1;
  rear = -1;
  Q = new Node *[size];
}

void Queue::enqueue(Node *x) {
  if ((rear + 1) % size == front) {
    cout << "Queue is full" << endl;
  } else {
    rear = (rear + 1) % size;
    Q[rear] = x;
  }
}

Node *Queue::dequeue() {
  Node *x = NULL;
  if (front == rear) {
    cout << "Queue is empty" << endl;
  } else {
    front = (front + 1) % size;
    x = Q[front];
  }
  return x;
}

int Queue::isEmpty() { return front == rear; }

class Tree {
private:
  Node *root = NULL;

public:
  void create();
  void preorder(Node *p);
  void inorder(Node *p);
  void postorder(Node *p);
  Node *getRoot() { return root; }
};

void Tree::create() {
  Node *p, *t;
  int x;
  Queue q;
  q.create(100);

  cout << "Enter root value : ";
  cin >> x;
  root = new Node;
  root->data = x;
  root->lchild = root->rchild = NULL;
  q.enqueue(root);

  while (!q.isEmpty()) {
    p = q.dequeue();
    cout << "Enter left child of " << p->data << " : ";
    cin >> x;
    if (x != -1) {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.enqueue(t);
    }

    cout << "Enter right child of " << p->data << " : ";
    cin >> x;
    if (x != -1) {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.enqueue(t);
    }
  }
}

void Tree::preorder(Node *p) {
  if (p) {
    cout << p->data << " ";
    preorder(p->lchild);
    preorder(p->rchild);
  }
  cout << endl;
}

void Tree::inorder(Node *p) {
  if (p) {
    preorder(p->lchild);
    cout << p->data << " ";
    preorder(p->rchild);
  }
  cout << endl;
}

void Tree::postorder(Node *p) {
  if (p) {
    preorder(p->lchild);
    preorder(p->rchild);
    cout << p->data << " ";
  }
  cout << endl;
}

int main() {
  Tree t;
  t.create();
  t.preorder(t.getRoot());
  t.inorder(t.getRoot());
  t.postorder(t.getRoot());

  return 0;
}