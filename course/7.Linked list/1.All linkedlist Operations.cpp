#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n) {
  int i;
  struct Node *t, *last;
  second = new Node;
  second->data = A[0];
  second->next = NULL;
  last = second;

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

void insert(struct Node *p, int pos, int x) {
  Node *t;
  t = new Node;
  t->data = x;
  if (pos == 0) {
    t->next = first;
    first = t;
  } else {
    for (int i = 0; i < pos - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void insertLast(struct Node *p, int x) {
  Node *t, *last;
  t = new Node;
  t->data = x;
  t->next = NULL;
  if (first == NULL) {
    first = last = t;
  } else {
    last->next = t;
    last = t;
  }
}

void insertSort(struct Node *p, int x) {
  Node *q, *t;
  p = first;
  q = NULL;

  while (p && p->data < x) {
    q = p;
    p = p->next;
  }
  t = new Node;
  t->data = x;
  t->next = q->next;
  q->next = t;
}

int Delete(struct Node *p, int index) {
  Node *q = NULL;
  int x = -1;

  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    delete q;
    return x;
  } else {
    for (int i = 0; i < index - 1; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    return x;
  }
}

bool isSorted(struct Node *p) {
  int x = -32789;
  while (p != NULL) {
    if (p->data < x) {
      return false;
    }
    x = p->data;
    p = p->next;
  }
  return true;
}

void duplicate(struct Node *p) {
  Node *q;
  p = first;
  q = p->next;

  while (q != NULL) {
    if (p->data != q->data) {
      p = q;
      q = q->next;
    } else {
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

void reverse(struct Node *p) {
  p = first;
  int i = 0;
  int A[Rcount(p)];
  while (p != NULL) {
    A[i] = p->data;
    p = p->next;
    i++;
  }
  p = first;
  i--;
  while (p != NULL) {
    p->data = A[i--];
    p = p->next;
  }
}

void IIreverse(struct Node *p) {
  Node *q, *r;
  p = first;
  q = NULL;
  r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void Rreverse(struct Node *q, struct Node *p) {

  if (p != NULL) {
    Rreverse(p, p->next);
    p->next = q;
  } else {
    first = q;
  }
}

void concatenation(struct Node *p, struct Node *q) {
  third = p;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = q;
}

void merge(struct Node *p, struct Node *q) {
  struct Node *last;
  if (p->data < q->data) {
    third = last = p;
    p = p->next;
    third->next = NULL;
  } else {
    third = last = q;
    q = q->next;
    third->next = NULL;
  }
  while (p && q) {
    if (p->data < q->data) {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    } else {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p)
    last->next = p;
  if (q)
    last->next = q;
}

int isLoop(struct Node *f) {
  struct Node *p, *q;
  p = q = f;
  do {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);

  if (p == q)
    return 1;
  return 0;
}

int main() {

  int A[] = {3, 5, 5, 6, 7, 10, 15, 15, 15};
  int B[] = {10, 20, 30, 40, 50};

  create(A, 9);
  create2(B, 5);

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

  insert(first, 9, 777);
  display(first);
  cout << endl;

  insertSort(first, 69);
  display(first);
  cout << endl;

  Delete(first, 2);
  display(first);
  cout << endl;

  cout << isSorted(first) << endl;

  duplicate(first);
  display(first);
  cout << endl;

  reverse(first);
  display(first);
  cout << endl;

  IIreverse(first);
  display(first);
  cout << endl;

  Rreverse(NULL, first);
  display(first);
  cout << endl;

  display(second);
  cout << endl;

  concatenation(first, second);
  display(third);
  cout << endl;

  // merge(first, second);
  // display(third);
  // cout << endl;

  cout << isLoop(first);

  return 0;
}