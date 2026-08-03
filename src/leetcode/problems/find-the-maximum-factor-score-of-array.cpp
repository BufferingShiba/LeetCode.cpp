#include "leetcode/problems/find-the-maximum-factor-score-of-array.h"

#include <numeric>

namespace leetcode::problem_3334 {

namespace {

long long gcd(long long a, long long b) {
  while (b) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

long long maxScoreImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  long long best = 0;

  // Option 1: remove no element.
  // Option 2: remove element at index i (i = -1 means remove none).
  for (int remove = -1; remove < n; ++remove) {
    long long cur_gcd = 0;  // gcd(0, x) = x
    long long cur_lcm = 1;
    bool first = true;
    for (int i = 0; i < n; ++i) {
      if (i == remove) continue;
      cur_gcd = gcd(cur_gcd, nums[i]);
      cur_lcm = first ? nums[i] : lcm(cur_lcm, nums[i]);
      first = false;
    }
    if (first) {
      best = std::max(best, 0LL);  // empty array score is 0
    } else {
      best = std::max(best, cur_gcd * cur_lcm);
    }
  }
  return best;
}

}  // namespace

long long FindTheMaximumFactorScoreOfArraySolution::maxScore(std::vector<int>& nums) {
  return getSolution()(nums);
}

FindTheMaximumFactorScoreOfArraySolution::FindTheMaximumFactorScoreOfArraySolution() {
  setMetaInfo({.id = 3334,
               .title = "Find the Maximum Factor Score of Array",
               .url = "https://leetcode.com/problems/find-the-maximum-factor-score-of-array/"});
  registerStrategy(
      {.name = "brute_force_remove_one",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Number Theory"}},
      maxScoreImpl);
}

}  // namespace leetcode::problem_3334
