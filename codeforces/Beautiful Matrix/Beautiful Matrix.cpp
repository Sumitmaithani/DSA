#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int arr[5][5], m, n, a, b;

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        m = i;
        n = j;
      }
    }
  }
  a = 2 - m;
  if (a < 0) {
    a *= -1;
  }
  b = 2 - n;
  if (b < 0) {
    b *= -1;
  }

  cout << a + b << endl;

  return 0;
}