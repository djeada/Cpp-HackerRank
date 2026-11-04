#include <exception>
#include <iostream>
#include <string>
using namespace std;

/* Define the exception here */

class BadLengthException : public std::exception {
private:
  string message;

public:
  explicit BadLengthException(int length) : message(to_string(length)) {}

  const char *what() const noexcept override { return message.c_str(); }
};

bool checkUsername(string username) {
  bool isValid = true;
  int n = username.length();
  if (n < 5) {
    throw BadLengthException(n);
  }
  for (int i = 0; i < n - 1; i++) {
    if (username[i] == 'w' && username[i + 1] == 'w') {
      isValid = false;
    }
  }
  return isValid;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string username;
    cin >> username;
    try {
      bool isValid = checkUsername(username);
      if (isValid) {
        cout << "Valid" << '\n';
      } else {
        cout << "Invalid" << '\n';
      }
    } catch (const BadLengthException &e) {
      cout << "Too short: " << e.what() << '\n';
    }
  }
  return 0;
}