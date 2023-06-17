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
};

void Stack::Create() {
  //int i;

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
  for (i = 0; i < st.size; i++) {
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
  if (st.top == -1) {
    cout << "Stack Underflow" << endl;
    return -1;
  } else {
    int x = st.S[st.top];
    st.top--;
    return x;
  }
}

int main() {
  Stack st;
  st.Create();
  st.Push(1);
  st.Push(2);
  st.Push(3);
  cout << "Popped element: " << st.Pop() << endl;
  st.Display();

  return 0;
}