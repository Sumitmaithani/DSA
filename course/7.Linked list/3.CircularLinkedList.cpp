#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *Head;

public:
  LinkedList() { Head = NULL; }
  LinkedList(int A[], int n);

  void Display();
  void RDisplay(Node *p);
  void Insert(int index, int n);
  void Delete(int index);
  Node *GetHead();
};

LinkedList::LinkedList(int A[], int n) {
  int i;
  Node *t, *last;
  Head = new Node;
  Head->data = A[0];
  Head->next = NULL;
  last = Head;

  for (i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
  last->next = Head;
}

void LinkedList::Display() {
  Node *p = Head;
  if (p) {
    do {
      cout << p->data << " ";
      p = p->next;
    } while (p != Head);
  }
  cout << endl;
}

void LinkedList::RDisplay(Node *p) {
  static int flag = 0;
  if (p != Head || flag == 0) {
    flag = 1;
    cout << p->data << ' ';
    RDisplay(p->next);
  }
  flag = 0;
}

void LinkedList::Insert(int index, int n) {
  Node *t = new Node, *p = Head;

  if (index == 0) {
    t->data = n;
    if (Head == NULL) {
      Head = t;
      Head->next = Head;
    } else {
      t->next = Head;
      while (p->next != Head) {
        p = p->next;
      }
      p->next = t;
      Head = t;
    }
  } else {
    t->data = n;
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void LinkedList::Delete(int index) {
  Node *p = Head, *q;
  if (index == 0) {
    while (p->next != Head) {
      p = p->next;
    }
    p->next = Head->next;
    delete Head;
    Head = p->next;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;
  }
}

Node *LinkedList::GetHead() { return Head; }

int main() {
  int A[] = {1, 2, 3, 4, 5, 6};
  LinkedList l(A, 6);

  l.Display();

  l.Insert(0, 0);

  l.RDisplay(l.GetHead()); // Use the GetHead() function to obtain the Head node

  cout << endl;

  l.Delete(0);

  l.Display();

  return 0;
}
