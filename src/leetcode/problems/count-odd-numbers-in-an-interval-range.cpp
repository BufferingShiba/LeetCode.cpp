#include "leetcode/problems/count-odd-numbers-in-an-interval-range.h"

namespace leetcode {
namespace problem_1523 {

namespace {

int countOddsImpl(int low, int high) {
  // Count of odd numbers in [0, n] is (n + 1) / 2.
  return (high + 1) / 2 - low / 2;
}

}  // namespace

CountOddNumbersInAnIntervalRangeSolution::CountOddNumbersInAnIntervalRangeSolution() {
  setMetaInfo({.id = 1523,
               .title = "Count Odd Numbers in an Interval Range",
               .url = "https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/"});
  registerStrategy(
      {.name = "math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      countOddsImpl);
}

int CountOddNumbersInAnIntervalRangeSolution::countOdds(int low, int high) {
  return getSolution()(low, high);
}

}  // namespace problem_1523
}  // namespace leetcode
