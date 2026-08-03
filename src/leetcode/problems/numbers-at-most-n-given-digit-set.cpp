#include "leetcode/problems/numbers-at-most-n-given-digit-set.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_902 {

static int atMostNGivenDigitSetImpl(std::vector<std::string>& digits, int n) {
  std::string s = std::to_string(n);
  int k = static_cast<int>(s.size());
  int m = static_cast<int>(digits.size());

  // precompute m^i for i = 0..k
  std::vector<long long> pow_m(k + 1, 1);
  for (int i = 1; i <= k; ++i) {
    pow_m[i] = pow_m[i - 1] * m;
  }

  long long total = 0;

  // Part 1: numbers with fewer than k digits
  for (int i = 1; i < k; ++i) {
    total += pow_m[i];
  }

  // Part 2: numbers with exactly k digits, lexicographically <= s
  for (int i = 0; i < k; ++i) {
    char c = s[i];
    int less_count = 0;
    for (const auto& d : digits) {
      if (d[0] < c)
        ++less_count;
      else
        break;
    }
    total += less_count * pow_m[k - i - 1];

    // check whether current digit of n is in the allowed set
    bool matched = false;
    for (const auto& d : digits) {
      if (d[0] == c) {
        matched = true;
        break;
      }
    }
    if (!matched) {
      return static_cast<int>(total);
    }
  }

  // n itself is constructible
  return static_cast<int>(total + 1);
}

NumbersAtMostNGivenDigitSetSolution::NumbersAtMostNGivenDigitSetSolution() {
  setMetaInfo({.id = 902,
               .title = "Numbers At Most N Given Digit Set",
               .url = "https://leetcode.com/problems/numbers-at-most-n-given-digit-set/"});
  registerStrategy({.name = "combinatorial_counting",
                    .expected = "Accepted",
                    .time_complexity = "O(k * m)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String", "Dynamic Programming"}},
                   atMostNGivenDigitSetImpl);
}

int NumbersAtMostNGivenDigitSetSolution::atMostNGivenDigitSet(
    std::vector<std::string>& digits, int n) {
  return getSolution()(digits, n);
}

}  // namespace problem_902
}  // namespace leetcode
