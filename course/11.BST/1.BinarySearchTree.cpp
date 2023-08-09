#include <iostream>
using namespace std;

class Node {
public:
  Node *lchild;
  int data;
  Node *rchild;
} *root = NULL;

class BST {
public:
  Node *getRoot() { return root; }
  void Insert(int key);
  void Inorder(Node *p);
  Node *Search(int key);
  Node *RInsert(Node *p, int key);
};

void BST::Insert(int key) {
  Node *t = root;
  Node *r, *p;

  if (root == NULL) {
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    root = p;
    return;
  }
  while (t) {
    r = t;
    if (key < t->data)
      t = t->lchild;
    else if (key > t->data)
      t = t->rchild;
    else
      return;
  }
  p = new Node;
  p->data = key;
  p->lchild = p->rchild = NULL;

  if (key < r->data)
    r->lchild = p;
  else
    r->rchild = p;
}

void BST::Inorder(Node *p) {
  if (p) {
    Inorder(p->lchild);
    cout << p->data << ' ';
    Inorder(p->rchild);
  }
}

Node *BST::Search(int key) {
  Node *t = root;
  while (t) {
    if (key == t->data)
      return t;
    else if (key < t->data)
      t = t->lchild;
    else
      t = t->rchild;
  }
  return NULL;
}

Node *BST::RInsert(Node *p, int key) {
  Node *t = NULL;

  if (p == NULL) {
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }

  if (key < p->data)
    p->lchild = RInsert(p->lchild, key);
  else if (key > p->data)
    p->rchild = RInsert(p->rchild, key);

  return p;
}

int main() {
  BST p;
  Node *temp;
  Node *res = p.getRoot();
  res = p.RInsert(p.getRoot(), 10);
  cout << res->data << endl;
  p.RInsert(res, 20);
  p.RInsert(res, 30);
  p.RInsert(res, 40);
  p.RInsert(res, 50);

  p.Inorder(p.getRoot());

  cout << endl;
  temp = p.Search(30);
  if (temp) {
    cout << temp->data;
  } else {
    cout << "Element is not found" << endl;
  }

  return 0;
}