#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  // Complete this function
  vector<int> integers;
  int flag = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ',') {
      integers.push_back(stoi(str.substr(flag, i)));
      flag = i + 1;
    }
  }
  integers.push_back(stoi(str.substr(flag, str.size())));
  return integers;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}