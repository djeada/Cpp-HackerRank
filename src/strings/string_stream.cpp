#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  vector<int> integers;

  // Approach 1 (active) reads comma-delimited fields with a string stream.
  istringstream input(str);
  string field;
  while (getline(input, field, ',')) {
    integers.push_back(stoi(field));
  }

  // Approach 2 uses string offsets. Replace the stream loop above.
  /*
  string::size_type start = 0;
  for (auto comma = str.find(','); comma != string::npos;
       comma = str.find(',', start)) {
    integers.push_back(stoi(str.substr(start, comma - start)));
    start = comma + 1;
  }
  if (start < str.size()) {
    integers.push_back(stoi(str.substr(start)));
  }
  */

  return integers;
}

int main() {
  string str;
  cin >> str;
  for (int value : parseInts(str)) {
    cout << value << '\n';
  }
}
