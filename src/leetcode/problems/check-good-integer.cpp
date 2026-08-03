#include "leetcode/problems/check-good-integer.h"

namespace leetcode {
namespace problem_3959 {

namespace {

bool checkGoodIntegerImpl(int n) {
  int digitSum = 0;
  int squareSum = 0;
  int x = n;
  while (x > 0) {
    int d = x % 10;
    digitSum += d;
    squareSum += d * d;
    x /= 10;
  }
  return (squareSum - digitSum) >= 50;
}

}  // namespace

CheckGoodIntegerSolution::CheckGoodIntegerSolution() {
  setMetaInfo({.id = 3959,
               .title = "Check Good Integer",
               .url = "https://leetcode.com/problems/check-good-integer/"});

  registerStrategy(
      {.name = "digit-sum-simulation",
       .expected = "Accepted",
       .time_complexity = "O(log10(n))",
       .space_complexity = "O(1)",
       .tags = {"math", "simulation"}},
      checkGoodIntegerImpl);
}

bool CheckGoodIntegerSolution::checkGoodInteger(int n) {
  return getSolution()(n);
}

}  // namespace problem_3959
}  // namespace leetcode
