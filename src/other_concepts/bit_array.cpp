#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

constexpr int modulus_bits = 31;
constexpr uint64_t mask = (uint64_t{1} << modulus_bits) - 1;

// Approach 1 (active) finds the period using powers of the affine transform.
// At most modulus_bits squarings or sequence steps, with constant space.
uint64_t count_distinct(uint64_t n, uint64_t seed, uint64_t multiplier,
                        uint64_t increment) {
  seed &= mask;
  multiplier &= mask;
  increment &= mask;

  if (multiplier % 2 == 0) {
    // Each step adds a factor of two to the difference between neighbors.
    // The sequence can repeat only once it reaches a fixed point.
    uint64_t current = seed;
    for (uint64_t count = 1; count < n; ++count) {
      const uint64_t next = (multiplier * current + increment) & mask;
      if (next == current) {
        return count;
      }
      current = next;
    }
    return n;
  }

  // An odd multiplier makes the transform invertible, so the first repeat is
  // the seed. Squaring lifts the identity modulo 2^k to modulo 2^(k+1),
  // so the period divides 2^31 and must be a power of two.
  uint64_t period = 1;
  while (period < n && ((multiplier * seed + increment) & mask) != seed) {
    increment = (multiplier * increment + increment) & mask;
    multiplier = (multiplier * multiplier) & mask;
    period *= 2;
  }
  return min(n, period);
}

// Approach 2 walks the sequence in O(n) time and O(1) space. Replace the
// active count_distinct function with this one to use it.
/*
uint64_t count_distinct(uint64_t n, uint64_t seed, uint64_t multiplier,
                        uint64_t increment) {
  seed &= mask;
  uint64_t current = seed;
  for (uint64_t count = 1; count < n; ++count) {
    const uint64_t next = (multiplier * current + increment) & mask;
    if (next == current || next == seed) {
      return count;
    }
    current = next;
  }
  return n;
}
*/

int main() {
  uint64_t n, seed, multiplier, increment;
  cin >> n >> seed >> multiplier >> increment;
  cout << count_distinct(n, seed, multiplier, increment) << '\n';
}
