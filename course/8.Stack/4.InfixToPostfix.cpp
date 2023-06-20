#include <cstring>
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
  int Pre(char x);
  int isOperand(char x);
  char *InToPost(char *infix);
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

int Stack::Pre(char x) {
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  return 0;
}

int Stack::isOperand(char x) {
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
  else
    return 1;
}

char *Stack::InToPost(char *infix) {
  int i = 0, j = 0;
  char *postfix;
  int len = strlen(infix);
  postfix = new char[len + 2];

  while (infix[i] != '/0') {
    if (isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else {
      if (Pre(infix[i]) > Pre(top->data))
        Push(infix[i++]);
      else {
        postfix[j++] = Pop();
      }
    }
  }
  while (top != NULL)
    postfix[j++] = Pop();
  postfix[j] = '/0';
  return postfix;
}

int main() {
  char *infix = "a+b*c";
  Stack stk;
  stk.Push('#');
  char *postfix = stk.InToPost(infix);
  cout << postfix << endl;

  return 0;
}