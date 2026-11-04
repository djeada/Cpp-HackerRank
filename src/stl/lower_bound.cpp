#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int>::const_iterator first_at_least(const vector<int> &numbers, int value) {
  // Approach 1 (active) uses the standard library binary search.
  return lower_bound(numbers.begin(), numbers.end(), value);

  // Approach 2 implements the same search over a half-open range.
  /*
  auto first = numbers.begin();
  auto last = numbers.end();
  while (first != last) {
    auto middle = first + (last - first) / 2;
    if (*middle < value) {
      first = middle + 1;
    } else {
      last = middle;
    }
  }
  return first;
  */
}

int main() {
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int &number : numbers) {
    cin >> number;
  }

  int queries;
  cin >> queries;
  for (int i = 0; i < queries; ++i) {
    int value;
    cin >> value;
    const auto found = first_at_least(numbers, value);
    const bool exact = found != numbers.end() && *found == value;
    cout << (exact ? "Yes " : "No ") << (found - numbers.begin() + 1) << '\n';
  }
}
