#include <iostream>
using namespace std;

class Node {
public:
  Node *prev;
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *first;

public:
  LinkedList() { first = NULL; };
  LinkedList(int A[], int n);

  void Display();
  int length();
  void Insert(int ele, int index);
};

LinkedList::LinkedList(int A[], int n) {
  Node *t, *last;

  first = new Node;
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for (int i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

void LinkedList::Display() {
  Node *p = first;
  while (p) {
    cout << p->data << ' ';
    p = p->next;
  }
  cout << endl;
}

int LinkedList::length() {
  Node *p = first;
  int len = 0;
  while (p) {
    len++;
    p = p->next;
  }
  return len;
}

void LinkedList::Insert(int ele, int index) {
  Node *t;
  Node *p = first;

  if (index == 0) {
    t = new Node;
    t->prev = NULL;
    t->data = ele;
    t->next = first;
    first->prev = t;
    first = t;
  } else {
    t = new Node;
    t->data = ele;
    for (int i = 0; i < index - 1; i++)
      p = p->next;
    t->prev = p;
    t->next = p->next;
    if (p->next)
      p->next->prev = t;
    p->next = t;
  }
}

int main() {
  int A[] = {10, 20, 30, 40, 50, 60};
  LinkedList d(A, 6);

  d.Display();

  cout << d.length() << endl;

  d.Insert(0, 0);

  d.Insert(45, 5);

  d.Display();

  return 0;
}