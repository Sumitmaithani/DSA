#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int a, b;
    int ans1 = INT_MIN, ans2;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      if (a <= 10) {
        if (ans1 < b) {
          ans1 = b;
          ans2 = i;
        }
      }
    }
    cout << ans2 + 1 << endl;
  }

  return 0;
}