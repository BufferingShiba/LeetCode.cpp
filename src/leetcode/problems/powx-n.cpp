#include "leetcode/problems/powx-n.h"

#include <cstdint>

namespace leetcode {
namespace problem_50 {

namespace {

double powxnImpl(double x, int n) {
  // Use long to avoid overflow when n == INT_MIN (-n overflows int).
  long exp = n;
  if (exp < 0) {
    x = 1.0 / x;
    exp = -exp;
  }
  double result = 1.0;
  while (exp > 0) {
    if (exp & 1) {
      result *= x;
    }
    x *= x;
    exp >>= 1;
  }
  return result;
}

}  // namespace

PowxNSolution::PowxNSolution() {
  setMetaInfo({.id = 50,
               .title = "Pow(x, n)",
               .url = "https://leetcode.com/problems/powx-n/"});

  registerStrategy({.name = "FastPowerIterative",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Recursion", "Binary"},
                    .notes = "Binary exponentiation; use long for n to handle INT_MIN"},
                   powxnImpl);
}

double PowxNSolution::myPow(double x, int n) {
  return getSolution()(x, n);
}

}  // namespace problem_50
}  // namespace leetcode
