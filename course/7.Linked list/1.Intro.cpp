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

int max(struct Node *p) {
  int m = -32768, MIN_INT;
  while (p != NULL) {
    if (p->data > m) {
      m = p->data;
    }
    p = p->next;
  }
  return m;
}

int Rmax(struct Node *p) {
  int MIN_INT;
  int x = 0;
  if (p == NULL)
    return MIN_INT;
  x = max(p->next);
  return x > p->data ? x : p->data;
}

int search(struct Node *p, int key) {
  while (p != NULL) {
    if (key == p->data)
      return p->data;
    p = p->next;
  }
  return 0;
}

int Rsearch(struct Node *p, int key) {
  if (p == NULL)
    return 0;
  if (key == p->data)
    return p->data;
  return Rsearch(p->next, key);
}

Node *IIsearch(struct Node *p, int key) {
  Node *q = NULL;
  while (p != NULL) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
}

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
  cout << max(first) << endl;
  cout << Rmax(first) << endl;
  cout << search(first, 7) << endl;
  cout << Rsearch(first, 17) << endl;
  cout << IIsearch(first, 7) << endl;
  display(first);
  cout << endl;

  return 0;
}