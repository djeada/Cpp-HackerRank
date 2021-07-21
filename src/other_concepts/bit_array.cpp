#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto po = (uint_fast64_t)(pow(2, 31));
  uint_fast64_t N, S, P, Q;
  cin >> N >> S >> P >> Q;

  bool r = false;
  auto c = 0;
  auto prv = S % po;
  auto crn = -1;
  auto i = 1;

  while (i < N && !r) {
    crn = (prv * P + Q) % po;
    if (crn != prv) {
      prv = crn;
      ++c;
    } else
      r = true;
    i++;
  }
  cout << c + 1 << endl;

  return 0;
}
