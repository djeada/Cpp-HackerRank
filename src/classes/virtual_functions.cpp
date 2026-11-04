#include <array>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
  string name;
  int age;

public:
  virtual ~Person() = default;
  virtual void putdata() = 0;
  virtual void getdata() = 0;
};

class Professor : public Person {
  static int next_id;
  const int cur_id;
  int publications;

public:
  Professor() : cur_id(++next_id) {}

  void putdata() override {
    cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
  }

  void getdata() override { cin >> name >> age >> publications; }
};

int Professor::next_id = 0;

class Student : public Person {
  static int next_id;
  const int cur_id;
  array<int, 6> marks;

public:
  Student() : cur_id(++next_id) {}

  void putdata() override {
    const int total = accumulate(marks.begin(), marks.end(), 0);
    cout << name << ' ' << age << ' ' << total << ' ' << cur_id << '\n';
  }

  void getdata() override {
    cin >> name >> age;
    for (int &mark : marks) {
      cin >> mark;
    }
  }
};

int Student::next_id = 0;

int main() {
  int n;
  cin >> n;
  vector<unique_ptr<Person>> people(n);

  for (auto &person : people) {
    int type;
    cin >> type;
    if (type == 1) {
      person.reset(new Professor);
    } else {
      person.reset(new Student);
    }
    person->getdata();
  }

  for (const auto &person : people) {
    person->putdata();
  }
}
