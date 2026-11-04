#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int lines, queries;
  cin >> lines >> queries;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  map<string, string> attributes;
  vector<string> paths;
  for (int i = 0; i < lines; ++i) {
    string line;
    getline(cin, line);
    if (line.compare(0, 2, "</") == 0) {
      paths.pop_back();
      continue;
    }

    istringstream tag(line.substr(1, line.rfind('>') - 1));
    string name;
    tag >> name;
    paths.push_back(paths.empty() ? name : paths.back() + "." + name);

    while (tag >> ws && getline(tag, name, '=')) {
      name.erase(name.find_last_not_of(" \t") + 1);
      tag.ignore(numeric_limits<streamsize>::max(), '"');
      string value;
      if (getline(tag, value, '"')) {
        attributes[paths.back() + "~" + name] = value;
      }
    }
  }

  for (int i = 0; i < queries; ++i) {
    string query;
    cin >> query;
    const auto found = attributes.find(query);
    cout << (found == attributes.end() ? "Not Found!" : found->second) << '\n';
  }
}
