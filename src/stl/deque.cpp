#include <deque>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Approach 1 (active) keeps candidates in a monotonic deque in O(n) time.
void printKMax(int arr[], int n, int k) {
  deque<int> candidates;
  for (int i = 0; i < n; ++i) {
    if (!candidates.empty() && candidates.front() <= i - k) {
      candidates.pop_front();
    }
    while (!candidates.empty() && arr[candidates.back()] <= arr[i]) {
      candidates.pop_back();
    }
    candidates.push_back(i);

    if (i >= k - 1) {
      cout << arr[candidates.front()] << (i == n - 1 ? '\n' : ' ');
    }
  }
}

// Approach 2 keeps the current window in a multiset in O(n log k) time.
// Replace the active printKMax function to use it.
/*
void printKMax(int arr[], int n, int k) {
  multiset<int> window;
  for (int i = 0; i < n; ++i) {
    if (i >= k) {
      window.erase(window.find(arr[i - k]));
    }
    window.insert(arr[i]);
    if (i >= k - 1) {
      cout << *window.rbegin() << (i == n - 1 ? '\n' : ' ');
    }
  }
}
*/

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &value : arr) {
      cin >> value;
    }
    printKMax(arr.data(), n, k);
  }
}
