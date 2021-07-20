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

  int x;
  cin >> x;
  numbers.erase(numbers.begin() + x - 1);

  int a, b;
  cin >> a >> b;
  numbers.erase(numbers.begin() + a - 1, numbers.begin() + b - 1);

  cout << numbers.size() << endl;
  print_vector(numbers);

  return 0;
}