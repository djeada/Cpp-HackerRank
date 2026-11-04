#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int queries;
  cin >> queries;

  // Approach 1 (active) uses an ordered map for O(log n) operations.
  map<string, int> marks;
  // Approach 2 uses hashing for average O(1) operations. Replace the map above.
  // unordered_map<string, int> marks;

  for (int i = 0; i < queries; ++i) {
    int type;
    string name;
    cin >> type >> name;
    if (type == 1) {
      int score;
      cin >> score;
      marks[name] += score;
    } else if (type == 2) {
      marks.erase(name);
    } else if (type == 3) {
      const auto found = marks.find(name);
      cout << (found == marks.end() ? 0 : found->second) << '\n';
    }
  }
}
