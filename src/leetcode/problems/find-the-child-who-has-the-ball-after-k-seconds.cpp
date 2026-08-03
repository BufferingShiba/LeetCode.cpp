#include "leetcode/problems/find-the-child-who-has-the-ball-after-k-seconds.h"

namespace leetcode::problem_3178 {

namespace {

int numberOfChildImpl(int n, int k) {
  int period = 2 * (n - 1);
  int r = k % period;
  if (r < n - 1) {
    return r;
  }
  return period - r;
}

}  // namespace

FindTheChildWhoHasTheBallAfterKSecondsSolution::FindTheChildWhoHasTheBallAfterKSecondsSolution() {
  setMetaInfo({.id = 3178,
               .title = "Find the Child Who Has the Ball After K Seconds",
               .url = "https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/"});
  registerStrategy(
      {.name = "Math O(1)",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Simulation"}},
      numberOfChildImpl);
}

int FindTheChildWhoHasTheBallAfterKSecondsSolution::numberOfChild(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_3178
