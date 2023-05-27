#include <iostream>
using namespace std;

struct Term {
  int coef;
  int expo;
};

struct Polynomial {
  int n;
  struct Term *poly;
};

Polynomial *add(const Polynomial &p1, const Polynomial &p2) {

  int i, j, k;
  struct Polynomial *sum;

  sum = new Polynomial;
  sum->n = p1.n + p2.n;

  i = j = k = 0;

  while (i < p1.n && j < p2.n) {
    if (p1.poly[i].expo > p2.poly[i].expo)
      sum->poly[k++] = p1.poly[i++];
    else if (p1.poly[i].expo < p2.poly[j].expo)
      sum->poly[k++] = p2.poly[j++];
    else {
      sum->poly[k].expo = p1.poly[i].expo;
      sum->poly[k++].coef = p1.poly[i++].coef + p2.poly[j++].coef;
    }
  }

  for (; i < p1.n; i++)
    sum->poly[k++] = p1.poly[i];
  for (; j < p2.n; j++)
    sum->poly[k++] = p2.poly[j];

  sum->n = k;

  return sum;
}

int main() {
  struct Polynomial A, B, C;
  int i;

  cout << "Enter first polynomial number of terms : ";
  cin >> A.n;

  A.poly = new Term[A.n];

  cout << "Enter coefficient and exponents " << endl;
  for (i = 0; i < A.n; i++) {
    cout << "Enter term " << i << " cofficient and expoent value : ";
    cin >> A.poly[i].coef >> A.poly[i].expo;
  }

  for (i = 0; i < A.n; i++) {
    cout << A.poly[i].coef << "x"
         << "^" << A.poly[i].expo << " ";
  }

  cout << endl << "Enter second number of terms : ";
  cin >> B.n;

  B.poly = new Term[B.n];

  cout << "Enter coefficient and exponents " << endl;
  for (i = 0; i < B.n; i++) {
    cout << "Enter term " << i << " cofficient and expoent value : ";
    cin >> B.poly[i].coef >> B.poly[i].expo;
  }

  for (i = 0; i < B.n; i++) {
    cout << B.poly[i].coef << "x"
         << "^" << B.poly[i].expo << " ";
  }

  C = *add(A, B);

  cout << endl << "Sum of both polynomial is : " << endl;

  for (i = 0; i < C.n; i++) {
    cout << C.poly[i].coef << "x"
         << "^" << C.poly[i].expo << " ";
  }

  return 0;
}
