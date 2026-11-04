#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> values(n);
  for (int &value : values) {
    cin >> value;
  }

  // Approach 1 (active) traverses the array from the end without changing it.
  for (auto it = values.rbegin(); it != values.rend(); ++it) {
    if (it != values.rbegin()) {
      cout << ' ';
    }
    cout << *it;
  }

  // Approach 2 reverses the array in place. Replace the loop above.
  /*
  reverse(values.begin(), values.end());
  for (vector<int>::size_type i = 0; i < values.size(); ++i) {
    if (i != 0) {
      cout << ' ';
    }
    cout << values[i];
  }
  */
  cout << '\n';
}
