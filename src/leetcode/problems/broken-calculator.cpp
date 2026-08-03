#include "leetcode/problems/broken-calculator.h"

namespace leetcode {
namespace problem_991 {

static int solution1(int startValue, int target) {
  int ops = 0;
  while (target > startValue) {
    if (target % 2 == 0) {
      target /= 2;
    } else {
      target += 1;
    }
    ++ops;
  }
  return ops + (startValue - target);
}

BrokenCalculatorSolution::BrokenCalculatorSolution() {
  setMetaInfo({
      .id = 991,
      .title = "Broken Calculator",
      .url = "https://leetcode.com/problems/broken-calculator"
  });
  registerStrategy({.name = "Brute Force",
                    .expected = "Accepted",
                    .time_complexity = "O(log target)",
                    .space_complexity = "O(1)",
                    .tags = {"Greedy", "Math"}},
                   solution1);
}

int BrokenCalculatorSolution::brokenCalc(int startValue, int target) {
  return getSolution()(startValue, target);
}

}  // namespace problem_991
}  // namespace leetcode
