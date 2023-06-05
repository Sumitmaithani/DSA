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
  Node* GetHead(); // New function declaration
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
  last->next = Head; // Make the last node point back to Head to form a circular linked list
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

Node* LinkedList::GetHead() { // New function definition
  return Head;
}

int main() {
  int A[] = {1, 2, 3, 4, 5, 6};
  LinkedList l(A, 6);

  l.Display();
  l.RDisplay(l.GetHead()); // Use the GetHead() function to obtain the Head node

  return 0;
}
