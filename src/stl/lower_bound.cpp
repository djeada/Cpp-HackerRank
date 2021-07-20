#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> input_vector(int n) {
  vector<int> numbers;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    numbers.push_back(x);
  }
  return numbers;
}

int main() {
  int n, q, s;
  cin >> n;
  vector<int> numbers = input_vector(n);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s;
    int index =
        (lower_bound(numbers.begin(), numbers.end(), s) - numbers.begin());
    if (s == numbers[index]) {
      cout << "Yes " << index + 1 << "\n";
    } else {
      cout << "No " << index + 1 << "\n";
    }
  }
  return 0;
}