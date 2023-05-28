#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
} *first = NULL;

void create(int A[], int n) {
  int i;
  struct Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p) {
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
};

void Rdisplay(struct Node *p) {
  if (p != NULL) {
    cout << p->data << " ";
    Rdisplay(p->next);
  }
};

void count(struct Node *p) {
  int c = 0;
  while (p != NULL) {
    c++;
    p = p->next;
  }
  cout << c << endl;
};

int Rcount(struct Node *p) {
  if (p == NULL) {
    return 0;
  } else {
    return Rcount(p->next) + 1;
  }
};

int sum(struct Node *p) {
  int sum = 0;
  while (p != NULL) {
    sum += p->data;
    p = p->next;
  }
  return sum;
};

int Rsum(struct Node *p) {
  if (p == NULL) {
    return 0;
  } else {
    return Rsum(p->next) + p->data;
  }
};

int main() {

  int A[] = {3, 5, 6, 7, 10, 15};

  create(A, 6);

  display(first);
  cout << endl;
  Rdisplay(first);
  cout << endl;
  count(first);

  cout << Rcount(first) << endl;
  cout << sum(first) << endl;
  cout << Rsum(first) << endl;

  return 0;
}