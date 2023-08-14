#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, ans = INT_MAX;

  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      cout << 0 << endl;
      return;
    }
    ans = min(ans, 1 + (arr[i + 1] - arr[i]) / 2);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}