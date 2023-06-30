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
  void LevelOrder(Node *p);
  int Count(Node *root);
  int Height(Node *root);
  int Count0degLeaf(Node *root);
  int Count1degLeaf(Node *root);
  int Count2degLeaf(Node *root);
  int Count1_2degLeaf(Node *root);
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
}

void Tree::inorder(Node *p) {
  if (p) {
    preorder(p->lchild);
    cout << p->data << " ";
    preorder(p->rchild);
  }
}

void Tree::postorder(Node *p) {
  if (p) {
    preorder(p->lchild);
    preorder(p->rchild);
    cout << p->data << " ";
  }
}

void Tree::LevelOrder(Node *root) {
  Queue q;
  q.create(100);
  cout << root->data << " ";
  q.enqueue(root);

  while (!q.isEmpty()) {
    root = q.dequeue();
    if (root->lchild) {
      cout << root->lchild->data << " ";
      q.enqueue(root->lchild);
    }
    if (root->rchild) {
      cout << root->rchild->data << " ";
      q.enqueue(root->rchild);
    }
  }
}

int Tree::Count(Node *root) {
  int x, y;
  if (root) {
    x = Count(root->lchild);
    y = Count(root->rchild);
    return x + y + 1;
  }
  return 0;
}

int Tree::Height(Node *root) {
  int x, y;
  if (root == 0)
    return 0;
  x = Height(root->lchild);
  y = Height(root->rchild);
  if (x > y)
    return x + 1;
  return y + 1;
}

int Tree::Count0degLeaf(Node *root) {
  int x, y;
  if (root != NULL) {
    x = Count0degLeaf(root->lchild);
    y = Count0degLeaf(root->rchild);
    if (!root->lchild && !root->rchild)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int Tree::Count1degLeaf(Node *root) {
  int x, y;
  if (root != NULL) {
    x = Count1degLeaf(root->lchild);
    y = Count1degLeaf(root->rchild);
    if ((root->lchild && !root->rchild) || (!root->lchild && root->rchild))
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int Tree::Count2degLeaf(Node *root) {
  int x, y;
  if (root != NULL) {
    x = Count2degLeaf(root->lchild);
    y = Count2degLeaf(root->rchild);
    if (root->lchild && root->rchild)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int Tree::Count1_2degLeaf(Node *root) {
  int x, y;
  if (root != NULL) {
    x = Count1_2degLeaf(root->lchild);
    y = Count1_2degLeaf(root->rchild);
    if (root->lchild || root->rchild)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int main() {
  Tree t;
  t.create();
  t.preorder(t.getRoot());
  cout << endl;
  t.inorder(t.getRoot());
  cout << endl;
  t.postorder(t.getRoot());
  cout << endl;
  t.LevelOrder(t.getRoot());
  cout << endl << t.Count(t.getRoot()) << endl;
  cout << "Height : " << t.Height(t.getRoot()) << endl;
  cout << "0 deg Node : " << t.Count0degLeaf(t.getRoot()) << endl;
  cout << "1 deg Node : " << t.Count1degLeaf(t.getRoot()) << endl;
  cout << "2 deg Node : " << t.Count2degLeaf(t.getRoot()) << endl;
  cout << "1-2 deg Node : " << t.Count1_2degLeaf(t.getRoot()) << endl;

  return 0;
}