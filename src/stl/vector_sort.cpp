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

void print_vector(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  vector<int> numbers = input_vector(n);
  sort(numbers.begin(), numbers.end());
  print_vector(numbers);

  return 0;
}
