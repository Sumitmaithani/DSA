#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

void display(struct Node *p) {
  while (p->data != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
};

int main() {

  struct Node *A;

  return 0;
}