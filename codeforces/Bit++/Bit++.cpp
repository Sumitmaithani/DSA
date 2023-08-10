#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n, sum = 0;
  string op;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> op;
    if (op == "++X" || op == "X++") {
      sum += 1;
    } else {
      sum -= 1;
    }
  }

  cout << sum << endl;

  return 0;
}