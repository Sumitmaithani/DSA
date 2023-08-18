#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, a = 0, b = 0;
    cin >> n;

    vector<int> arr(n);
    vector<int> x;
    vector<int> y;
    vector<int> z;

    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      if (arr[i] % 2 == 0) {
        x.push_back(arr[i]);
      } else {
        y.push_back(arr[i]);
      }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < n; ++i) {
      if (arr[i] % 2 == 0) {
        z.push_back(x[a]);
        a++;
      } else {
        z.push_back(y[b]);
        b++;
      }
    }

    sort(arr.begin(), arr.end());

    bool sorted = true;

    for (int i = 0; i < n; ++i) {
      if (arr[i] != z[i]) {
        sorted = false;
        break;
      }
    }

    if (sorted) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}