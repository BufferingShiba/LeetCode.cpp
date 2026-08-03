#include "leetcode/problems/sum-of-primes-between-number-and-its-reverse.h"

#include <algorithm>

namespace leetcode::problem_3918 {

namespace {

bool isPrime(int x) {
  if (x < 2) {
    return false;
  }
  for (int d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

int reverseDigits(int x) {
  int rev = 0;
  while (x > 0) {
    rev = rev * 10 + x % 10;
    x /= 10;
  }
  return rev;
}

int sumOfPrimesInRangeImpl(int n) {
  int r = reverseDigits(n);
  int lo = std::min(n, r);
  int hi = std::max(n, r);
  int sum = 0;
  for (int x = lo; x <= hi; ++x) {
    if (isPrime(x)) {
      sum += x;
    }
  }
  return sum;
}

}  // namespace

SumOfPrimesBetweenNumberAndItsReverseSolution::
    SumOfPrimesBetweenNumberAndItsReverseSolution() {
  setMetaInfo({.id = 3918,
               .title = "Sum of Primes Between Number and Its Reverse",
               .url =
                   "https://leetcode.com/problems/sum-of-primes-between-number-\n"
                   "and-its-reverse/"});
  registerStrategy(
      {"TrialDivision",
       "Accepted",
       "O(max(n,r) * sqrt(max(n,r)))",
       "O(1)",
       {"Math", "Number Theory"}},
      sumOfPrimesInRangeImpl);
}

int SumOfPrimesBetweenNumberAndItsReverseSolution::sumOfPrimesInRange(
    int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3918
