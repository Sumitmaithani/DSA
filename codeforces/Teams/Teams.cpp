#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a == 0 && b == 0 && c == 0) || (a == 0 && b == 0) ||
        (b == 0 && c == 0) || (a == 0 && c == 0)) {
      sum += 0;
    } else {
      sum += 1;
    }
  }
  cout << sum << endl;

  return 0;
}