#include "leetcode/problems/count-commas-in-range.h"

namespace leetcode::problem_3870 {

namespace {

int countCommasImpl(int n) {
  // n <= 10^5 < 1,000,000, so each integer from 1..n has at most one comma
  // (only numbers >= 1000 carry one comma). Answer = count of x in [1, n]
  // with x >= 1000, which is max(0, n - 999).
  if (n < 1000) return 0;
  return n - 999;
}

}  // namespace

CountCommasInRangeSolution::CountCommasInRangeSolution() {
  setMetaInfo({.id = 3870, .title = "Count Commas in Range", .url = "https://leetcode.com/problems/count-commas-in-range/"});

  registerStrategy(
      {
          .name = "MathFormula",
          .expected = "Accepted",
          .time_complexity = "O(1)",
          .space_complexity = "O(1)",
          .tags = {"Math"},
      },
      countCommasImpl);

  setDefaultStrategy();
}

int CountCommasInRangeSolution::countCommas(int n) { return getSolution()(n); }

}  // namespace leetcode::problem_3870
