#include "leetcode/problems/check-digitorial-permutation.h"

namespace leetcode {
namespace problem_3848 {

// The sum of the factorials of the digits of a number depends only on its
// multiset of digits, which is invariant under permutation. Therefore a
// permutation of n is digitorial iff that factorial sum S = sum(digit!)
// has exactly the same digit multiset as n (making S itself a valid
// permutation of n that does not start with zero).
static bool solution1(int n) {
  auto digitFactorial = [](int d) {
    int res = 1;
    for (int i = 2; i <= d; ++i) res *= i;
    return res;
  };

  // Digit frequency of n.
  int freq[10] = {0};
  long long sum = 0;
  bool hasDigit = false;
  for (int t = n; t > 0; t /= 10) {
    int d = t % 10;
    freq[d]++;
    hasDigit = true;
    sum += digitFactorial(d);
  }
  // n >= 1 by constraints, so hasDigit is always true.
  (void)hasDigit;

  // Digit frequency of S.
  int sfreq[10] = {0};
  for (long long t = sum; t > 0; t /= 10) sfreq[t % 10]++;

  for (int i = 0; i < 10; ++i) {
    if (freq[i] != sfreq[i]) return false;
  }
  return true;
}

CheckDigitorialPermutationSolution::CheckDigitorialPermutationSolution() {
  setMetaInfo({
      .id = 3848,
      .title = "Check Digitorial Permutation",
      .url = "https://leetcode.com/problems/check-digitorial-permutation"
  });
  registerStrategy(
      {.name = "Brute Force", .time_complexity = "O(k)", .space_complexity = "O(1)", .tags = {"Math"}},
      solution1);
}

bool CheckDigitorialPermutationSolution::isDigitorialPermutation(int n) {
  return getSolution()(n);
}

}  // namespace problem_3848
}  // namespace leetcode
