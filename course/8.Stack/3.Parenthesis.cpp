#include <iostream>
using namespace std;

class Node {
public:
  char data;
  Node *next;
} *top = NULL;

class Stack {
private:
  Node *top;

public:
  Stack() { top = nullptr; };
  // ~Stack();
  void Push(char x);
  char Pop();
  void Display();
};

void Stack::Push(char x) {
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

char Stack::Pop() {
  Node *t;
  t = new Node;
  char x = -1;
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

int isBalanced(char *exp) {
  Stack stk;
  int i;
  for (i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(')
      stk.Push(exp[i]);
    else if (exp[i] == ')') {
      if (stk.Pop() == -1)
        return 0;
    }
  }
  if (top == NULL)
    return 1;
  return 0;
}

int isBalanced2(char *exp) {
  Stack stk;
  int i;
  char x;
  for (i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
      stk.Push(exp[i]);
    else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
      x = stk.Pop();
      if (x == -1)
        return 0;
      else if (!((x == '{' && exp[i] == '}') || (x == '[' && exp[i] == ']') ||
                 (x == '(' && exp[i] == ')'))) {
        return 0;
      }
    }
  }
  if (top == NULL)
    return 1;
  return 0;
}

int main() {
  char *exp = "((a+b)*(c+d))";
  cout << isBalanced(exp) << endl;

  char *exp2 = "{[(a+b)*(c+d)]}";
  cout << isBalanced2(exp2) << endl;

  return 0;
}