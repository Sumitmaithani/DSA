#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  unordered_map<char, int> m;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    m[s[i]]++;
  }

  if (m.size() % 2 == 0) {
    cout << "CHAT WITH HER!" << endl;
  } else {
    cout << "IGNORE HIM!" << endl;
  }

  return 0;
}