#include <cstring>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class Stack {
private:
  Node *top;

public:
  Stack() { top = nullptr; };
  // ~Stack();
  void Push(int x);
  int Pop();
  void Display();
  int Pre(char x);
  int isOperand(char x);
  char *InToPost(char *infix);
  int Eval(char *postfix);
};

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

  while (infix[i] != '\0') {
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
  postfix[j] = '\0';
  return postfix;
}

int Stack::Eval(char *postfix) {
  int x1, x2, r;
  for (int i = 0; postfix[i] != '\0'; i++) {
    if (isOperand(postfix[i])) {
      Push(postfix[i] - '0');
    } else {
      x2 = Pop();
      x1 = Pop();

      switch (postfix[i]) {
      case '+':
        r = x1 + x2;
        break;
      case '-':
        r = x1 - x2;
        break;
      case '*':
        r = x1 * x2;
        break;
      case '/':
        r = x1 / x2;
        break;
      }
      Push(r);
    }
  }
  return top->data;
}

int main() {
  char *infix = "a+b*c-d/e";
  Stack stk;
  //   stk.Push('#');
  //   char *postfix = stk.InToPost(infix);
  //   cout << postfix << endl;

  char *postfix = "234*+82/-";

  cout << "Result is " << stk.Eval(postfix);

  return 0;
}