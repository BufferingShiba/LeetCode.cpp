#include "leetcode/problems/minimum-operations-to-make-the-integer-zero.h"

namespace leetcode {
namespace problem_2749 {

static int solution1(int num1, int num2) {
  for (int k = 1; k <= 60; ++k) {
    long long x = static_cast<long long>(num1) - static_cast<long long>(k) * num2;
    if (x < 0) break;
    if (__builtin_popcountll(static_cast<unsigned long long>(x)) <= k && k <= x) {
      return k;
    }
  }
  return -1;
}

MinimumOperationsToMakeTheIntegerZeroSolution::MinimumOperationsToMakeTheIntegerZeroSolution() {
  setMetaInfo({
      .id = 2749,
      .title = "Minimum Operations to Make the Integer Zero",
      .url = "https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int MinimumOperationsToMakeTheIntegerZeroSolution::makeTheIntegerZero(int num1, int num2) {
  return getSolution()(num1, num2);
}

}  // namespace problem_2749
}  // namespace leetcode
