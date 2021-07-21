#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int start_up() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}

int static r = start_up();
/*Write the class AddElements here*/
template <class T> class AddElements {
private:
  T a;

public:
  AddElements(T &b) { a = b; }

  const T &add(T &n) {
    a += n;
    return a;
  }

  ~AddElements() {}
};

template <> class AddElements<string> {
private:
  string a;

public:
  AddElements(string &b) { a = b; }

  const string &concatenate(string &s) {
    a += s;
    return a;
  }

  ~AddElements() {}
};

int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "float") {
      double element1, element2;
      cin >> element1 >> element2;
      AddElements<double> myfloat(element1);
      cout << myfloat.add(element2) << endl;
    } else if (type == "int") {
      int element1, element2;
      cin >> element1 >> element2;
      AddElements<int> myint(element1);
      cout << myint.add(element2) << endl;
    } else if (type == "string") {
      string element1, element2;
      cin >> element1 >> element2;
      AddElements<string> mystring(element1);
      cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
