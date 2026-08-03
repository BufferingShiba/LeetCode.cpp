#include "leetcode/problems/climbing-stairs.h"

namespace leetcode {
namespace problem_70 {

static int solution1(int n) {
  if (n <= 2) return n;
  int prev = 1, curr = 2;
  for (int i = 3; i <= n; ++i) {
    int next = prev + curr;
    prev = curr;
    curr = next;
  }
  return curr;
}

ClimbingStairsSolution::ClimbingStairsSolution() {
  setMetaInfo({
      .id = 70,
      .title = "Climbing Stairs",
      .url = "https://leetcode.com/problems/climbing-stairs"
  });
  registerStrategy({.name = "Brute Force", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Dynamic Programming", "Math"}}, solution1);
}

int ClimbingStairsSolution::climbStairs(int n) {
  return getSolution()(n);
}

}  // namespace problem_70
}  // namespace leetcode
