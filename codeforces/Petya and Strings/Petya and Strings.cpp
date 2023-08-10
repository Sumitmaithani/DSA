#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

//convert uppercase letter to lowercase letter lowercase letter start from 97 (ascii) and uppercase end in 92.
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < 92) {
      a[i] += 32;
    }
    if (b[i] < 92) {
      b[i] += 32;
    }
  }

  if (a == b) {
    cout << 0 << endl;
  } else if (a > b) {
    cout << 1 << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}