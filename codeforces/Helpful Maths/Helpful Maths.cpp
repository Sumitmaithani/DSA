#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  vector<int> nums;
  string str;
  cin >> str;

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 1 || str[i] == 2 || str[i] == 3) {
      nums.push_back(str[i]);
    }
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i];
    if (i != nums.size() - 1) {
      cout << "+";
    }
  }
  cout << endl;

  return 0;
}