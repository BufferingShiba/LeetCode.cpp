#include "leetcode/problems/three-divisors.h"

namespace leetcode {
namespace problem_1952 {

static bool solution1(int n) {
  // A number has exactly three positive divisors iff it is the square of a
  // prime p (divisors: 1, p, p^2).
  if (n <= 3) return false;
  int root = static_cast<int>(std::sqrt(n));
  if (root * root != n) return false;  // not a perfect square
  // n = root^2; check that root is prime.
  if (root < 2) return false;
  for (int i = 2; i * i <= root; ++i) {
    if (root % i == 0) return false;
  }
  return true;
}

ThreeDivisorsSolution::ThreeDivisorsSolution() {
  setMetaInfo({
      .id = 1952,
      .title = "Three Divisors",
      .url = "https://leetcode.com/problems/three-divisors"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool ThreeDivisorsSolution::isThree(int n) {
  return getSolution()(n);
}

}  // namespace problem_1952
}  // namespace leetcode
