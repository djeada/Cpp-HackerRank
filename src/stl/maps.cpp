#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, type, value;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> type >> value;
    if (type == 1) {
      s.insert(value);
    } else if (type == 2) {
      s.erase(value);
    } else if (type == 3) {
      if (s.find(value) != s.end()) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
