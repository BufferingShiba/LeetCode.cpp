#include "leetcode/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k.h"

namespace leetcode::problem_3091 {

namespace {

int minOperationsImpl(int k) {
  int best = k - 1;  // start with single element = k only via increments
  // v = final single-element value (after increments). v ranges [1, k].
  for (int v = 1; v <= k; ++v) {
    int increments = v - 1;
    int copies = (k + v - 1) / v - 1;  // ceil(k/v) - 1
    if (copies < 0) copies = 0;
    int ops = increments + copies;
    if (ops < best) best = ops;
  }
  return best;
}

}  // namespace

ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution::
    ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution() {
  setMetaInfo({.id = 3091,
               .title = "Apply Operations to Make Sum of Array Greater Than or Equal to k",
               .url = "https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/"});
  registerStrategy({.name = "enumerate-final-value",
                    .expected = "Accepted",
                    .time_complexity = "O(k)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Greedy", "Enumeration"}},
                   minOperationsImpl);
}

int ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution::minOperations(int k) {
  return getSolution()(k);
}

}  // namespace leetcode::problem_3091
