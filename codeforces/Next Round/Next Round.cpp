#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  int n, k, b, sum = 0;
  vector<int> a;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> b;
    a.push_back(b);
  }

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] >= a[k-1] && a[i] > 0) {
      sum += 1;
    }
  }

  cout << sum << endl;

  return 0;
}