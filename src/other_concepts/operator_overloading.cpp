#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
  vector<vector<int>> a;
  Matrix operator+(Matrix &b) {
    Matrix result;
    for (size_t i = 0; i < a.size(); i++) {
      vector<int> bv;
      for (size_t j = 0; j < a[i].size(); j++)
        bv.push_back(a[i][j] + b.a[i][j]);
      result.a.push_back(bv);
    }
    return result;
  }
};

int main() {
  int cases, k;
  cin >> cases;
  for (k = 0; k < cases; k++) {
    Matrix x;
    Matrix y;
    Matrix result;
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      x.a.push_back(b);
    }
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      y.a.push_back(b);
    }
    result = x + y;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cout << result.a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
