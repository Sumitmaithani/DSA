#include <iostream>
using namespace std;

class Node {
public:
  int size;
  int top;
  int *S;
};

class Stack {
private:
  Node st;

public:
  void Create();
  void Display();
  void Push(int x);
  int Pop();
  int Peek(int index);
  int isEmpty();
  int isFull();
  int StackTop();
};

void Stack::Create() {
  // int i;

  cout << "Enter size : ";
  cin >> st.size;
  st.top = -1;
  st.S = new int[st.size];

  //   cout << "Enter element : ";
  //   for (i = 0; i < st.size; i++) {
  //     cin >> st.S[i];
  //     st.top++;
  //   }
};

void Stack::Display() {
  int i;
  for (i = st.top; i >= 0; i--) {
    cout << st.S[i] << " ";
  }
  cout << endl;
};

void Stack::Push(int x) {
  if (st.top == st.size - 1) {
    cout << "Stack Overflow" << endl;
  } else {
    st.top++;
    st.S[st.top] = x;
  }
};

int Stack::Pop() {
  int x = -1;
  if (st.top == -1) {
    cout << "Stack Underflow" << endl;
  } else {
    x = st.S[st.top];
    st.top--;
  }
  return x;
}

int Stack::Peek(int index) {
  int x;
  if (st.top - index + 1 < 0)
    cout << "Invalid index" << endl;
  x = st.S[st.top - index + 1];
  return x;
};

int Stack::isEmpty() {
  if (st.top == -1)
    return 1;
  return 0;
};

int Stack::isFull() {
  if (st.top == st.size - 1)
    return 1;
  return 0;
};

int Stack::StackTop() {
  if (!isEmpty())
    return st.S[st.top];
  return -1;
}

int main() {
  Stack st;
  st.Create();
  st.Push(1);
  st.Push(2);
  st.Push(3);
  st.Push(4);
  st.Push(5);
  cout << "Popped element: " << st.Pop() << endl;
  cout << "Popped element: " << st.Pop() << endl;
  cout << "Popped element: " << st.Pop() << endl;
  cout << "Peeked element: " << st.Peek(1) << endl;
  cout << st.isEmpty() << endl;
  cout << st.isFull() << endl;
  cout << st.StackTop() << endl;
  st.Display();

  return 0;
}