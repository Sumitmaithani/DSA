#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
} *top = NULL;

class Stack {
private:
  Node *top;

public:
  Stack() { top = nullptr; };
  // ~Stack();
  void Push(int x);
  int Pop();
  void Display();
};

// Stack::Stack(/* args */) {}

// Stack::~Stack() {}

void Stack::Push(int x) {
  Node *t;
  t = new Node;
  if (t == NULL) {
    cout << "Stack is full" << endl;
  } else {
    t->data = x;
    t->next = top;
    top = t;
  }
};

int Stack::Pop() {
  Node *t;
  t = new Node;
  int x = -1;
  if (top == NULL)
    cout << "Stack is empty" << endl;
  else {
    t = top;
    top = top->next;
    x = t->data;
    delete t;
  }
  return x;
};

void Stack::Display() {
  Node *p;
  p = top;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  };
  cout << endl;
};

int main() {
  Stack st;
  st.Push(10);
  st.Push(20);
  st.Push(30);
  st.Pop();
  st.Display();

  return 0;
}