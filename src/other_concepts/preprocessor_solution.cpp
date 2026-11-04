#include <climits>
#include <iostream>
#include <vector>

#define INF INT_MAX
#define FUNCTION(name, op)                                                     \
  inline void name(int &current, int candidate) {                               \
    if (candidate op current) {                                                \
      current = candidate;                                                     \
    }                                                                          \
  }
#define io(v) cin >> v
#define toStr(str) #str
#define foreach(v, i) for (decltype((v).size()) i = 0; i < (v).size(); ++i)

using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  foreach (v, i) { io(v)[i]; }
  int mn = INF;
  int mx = INT_MIN;
  foreach (v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  const long long ans = static_cast<long long>(mx) - mn;
  cout << toStr(Result =) << ' ' << ans << '\n';
  return 0;
}
