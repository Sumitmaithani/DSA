#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n != 2) {
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}