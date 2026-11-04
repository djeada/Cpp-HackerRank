#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Spell {
private:
  string scrollName;

public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() { return scrollName; }
};

class Fireball : public Spell {
private:
  int power;

public:
  Fireball(int power) : power(power) {}
  void revealFirepower() { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
private:
  int power;

public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
private:
  int power;

public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
private:
  int power;

public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
public:
  static string journal;
  static string read() { return journal; }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  if (dynamic_cast<Fireball *>(spell)) {
    dynamic_cast<Fireball *>(spell)->revealFirepower();
    return;
  }
  if (dynamic_cast<Frostbite *>(spell)) {
    dynamic_cast<Frostbite *>(spell)->revealFrostpower();
    return;
  }
  if (dynamic_cast<Thunderstorm *>(spell)) {
    dynamic_cast<Thunderstorm *>(spell)->revealThunderpower();
    return;
  }
  if (dynamic_cast<Waterbolt *>(spell)) {
    dynamic_cast<Waterbolt *>(spell)->revealWaterpower();
    return;
  }

  auto scroll = spell->revealScrollName();
  auto journal = SpellJournal::read();
  if (scroll.size() < journal.size()) {
    scroll.swap(journal);
  }

  // Approach 1 (active) computes LCS with O(min(m, n)) extra space.
  vector<int> lcs(journal.size() + 1, 0);
  for (char letter : scroll) {
    int diagonal = 0;
    for (string::size_type j = 0; j < journal.size(); ++j) {
      const int above = lcs[j + 1];
      lcs[j + 1] = letter == journal[j] ? diagonal + 1 : max(above, lcs[j]);
      diagonal = above;
    }
  }
  cout << lcs.back() << '\n';

  // Approach 2 stores the full O(m * n) table. Replace the rolling row above.
  /*
  vector<vector<int>> lcs(scroll.size() + 1, vector<int>(journal.size() + 1, 0));
  for (string::size_type i = 0; i < scroll.size(); ++i) {
    for (string::size_type j = 0; j < journal.size(); ++j) {
      lcs[i + 1][j + 1] = scroll[i] == journal[j]
                              ? lcs[i][j] + 1
                              : max(lcs[i][j + 1], lcs[i + 1][j]);
    }
  }
  cout << lcs.back().back() << '\n';
  */
}

class Wizard {
public:
  Spell *cast() {
    Spell *spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    unique_ptr<Spell> spell(Arawn.cast());
    counterspell(spell.get());
  }
  return 0;
}
