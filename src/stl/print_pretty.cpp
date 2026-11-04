#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    double a, b, c;
    cin >> a >> b >> c;

    cout << "0x" << hex << nouppercase << static_cast<long long>(a) << '\n';
    cout << right << setw(15) << setfill('_') << showpos << fixed
         << setprecision(2) << b << '\n';
    cout << uppercase << noshowpos << scientific << setprecision(9)
         << c << '\n';
  }
}
