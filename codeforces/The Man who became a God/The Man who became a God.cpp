#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, dif, sum = 0, temp;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    vector<int> dx(n - 1);
    for (int i = 1; i < n; ++i) {
      dif = abs(arr[i] - arr[i - 1]);
      sum += dif;
      dx.push_back(dif);
    }

    sort(dx.begin(), dx.end());
    k--;
    while (k--) {
      temp = dx.back();
      sum -= temp;
      dx.pop_back();
    }
    cout << sum << endl;
  }

  return 0;
}