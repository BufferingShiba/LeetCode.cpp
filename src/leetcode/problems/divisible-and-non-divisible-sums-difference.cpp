#include "leetcode/problems/divisible-and-non-divisible-sums-difference.h"

namespace leetcode {
namespace problem_2894 {
namespace {

int differenceOfSumsImpl(int n, int m) {
  int num1 = 0;
  int num2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % m == 0) {
      num2 += i;
    } else {
      num1 += i;
    }
  }
  return num1 - num2;
}

}  // namespace

DivisibleAndNonDivisibleSumsDifferenceSolution::
    DivisibleAndNonDivisibleSumsDifferenceSolution() {
  setMetaInfo({.id = 2894,
               .title = "Divisible and Non-divisible Sums Difference",
               .url = "https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      differenceOfSumsImpl);
}

int DivisibleAndNonDivisibleSumsDifferenceSolution::differenceOfSums(int n,
                                                                     int m) {
  return getSolution()(n, m);
}

}  // namespace problem_2894
}  // namespace leetcode
