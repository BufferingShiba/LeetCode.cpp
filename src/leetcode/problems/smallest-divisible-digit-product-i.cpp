#include "leetcode/problems/smallest-divisible-digit-product-i.h"

namespace leetcode::problem_3345 {

namespace {

int digitProduct(int x) {
  if (x == 0) return 0;
  int product = 1;
  while (x > 0) {
    product *= (x % 10);
    x /= 10;
  }
  return product;
}

int smallestNumberImpl(int n, int t) {
  for (int i = n; ; ++i) {
    if (digitProduct(i) % t == 0) {
      return i;
    }
  }
}

}  // namespace

SmallestDivisibleDigitProductISolution::SmallestDivisibleDigitProductISolution() {
  setMetaInfo({.id = 3345,
               .title = "Smallest Divisible Digit Product I",
               .url = "https://leetcode.com/problems/smallest-divisible-digit-product-i/"});
  registerStrategy(
      {.name = "Brute Force Enumeration",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Enumeration"}},
      smallestNumberImpl);
  setDefaultStrategy();
}

int SmallestDivisibleDigitProductISolution::smallestNumber(int n, int t) {
  return getSolution()(n, t);
}

}  // namespace leetcode::problem_3345
