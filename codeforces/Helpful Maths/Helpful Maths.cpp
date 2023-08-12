#include <bits/stdc++.h>

using namespace std;

int main() {
  map<char, int> m;
  string str;
  cin >> str;

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != '+') {
      m[str[i]]++;
    }
  }
  int c = 0;
  for (auto x : m) {
    while (x.second) {
      cout << x.first;
      c++;
      x.second--;
      if (c < str.size() / 2 + 1) {
        cout << '+';
      }
    }
  }
  cout << endl;

  return 0;
}