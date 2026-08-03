#include "leetcode/problems/number-of-steps-to-reduce-a-number-to-zero.h"

namespace leetcode {
namespace problem_1342 {

static int numberOfStepsImpl(int num) {
  int steps = 0;
  while (num > 0) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num -= 1;
    }
    ++steps;
  }
  return steps;
}

NumberOfStepsToReduceANumberToZeroSolution::NumberOfStepsToReduceANumberToZeroSolution() {
  setMetaInfo({.id = 1342,
               .title = "Number of Steps to Reduce a Number to Zero",
               .url = "https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"}},
      numberOfStepsImpl);
  setDefaultStrategy();
}

int NumberOfStepsToReduceANumberToZeroSolution::numberOfSteps(int num) {
  return getSolution()(num);
}

}  // namespace problem_1342
}  // namespace leetcode
