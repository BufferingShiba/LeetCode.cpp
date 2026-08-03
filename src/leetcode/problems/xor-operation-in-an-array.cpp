#include "leetcode/problems/xor-operation-in-an-array.h"

namespace leetcode::problem_1486 {

namespace {

int xorOperationImpl(int n, int start) {
  int result = 0;
  for (int i = 0; i < n; ++i) {
    result ^= start + 2 * i;
  }
  return result;
}

}  // namespace

XorOperationInAnArraySolution::XorOperationInAnArraySolution() {
  this->setMetaInfo({.id = 1486,
                     .title = "XOR Operation in an Array",
                     .url = "https://leetcode.com/problems/xor-operation-in-an-array/"});
  this->registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"}},
      xorOperationImpl);
}

int xorOperation(int n, int start) {
  XorOperationInAnArraySolution solution;
  solution.setDefaultStrategy();
  return solution.getSolution()(n, start);
}

}  // namespace leetcode::problem_1486
