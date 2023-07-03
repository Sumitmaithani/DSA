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

int main() {
  BST p;
  Node *temp;
  p.Insert(10);
  p.Insert(30);
  p.Insert(20);
  p.Insert(50);
  p.Insert(40);

  p.Inorder(p.getRoot());

  cout << endl;
  temp = p.Search(30);
  if (temp) {
    cout << temp->data;
  } else{
    cout<<"Element is not found"<<endl;
  }

  return 0;
}