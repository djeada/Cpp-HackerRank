#include <cstdio>
#include <iomanip>
#include <iostream>

int main() {
  int i;
  long long l;
  char ch;
  float f;
  double d;

  // Approach 1 (active) uses C stdio format specifiers.
  if (std::scanf("%d %lld %c %f %lf", &i, &l, &ch, &f, &d) != 5) {
    return 0;
  }
  std::printf("%d\n%lld\n%c\n%.3f\n%.9f\n", i, l, ch, f, d);

  // Approach 2 uses C++ streams. Replace the stdio block above.
  /*
  if (!(std::cin >> i >> l >> ch >> f >> d)) {
    return 0;
  }
  std::cout << i << '\n' << l << '\n' << ch << '\n'
            << std::fixed << std::setprecision(3) << f << '\n'
            << std::setprecision(9) << d << '\n';
  */
}
