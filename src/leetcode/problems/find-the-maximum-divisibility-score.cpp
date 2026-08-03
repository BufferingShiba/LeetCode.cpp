#include "leetcode/problems/find-the-maximum-divisibility-score.h"

namespace leetcode {
namespace problem_2644 {

namespace {

int maxDivScoreImpl(std::vector<int>& nums, std::vector<int>& divisors) {
  int best = -1;
  int bestScore = -1;
  for (int d : divisors) {
    int score = 0;
    for (int n : nums) {
      if (n % d == 0) ++score;
    }
    if (score > bestScore || (score == bestScore && d < best)) {
      bestScore = score;
      best = d;
    }
  }
  return best;
}

}  // namespace

FindTheMaximumDivisibilityScoreSolution::FindTheMaximumDivisibilityScoreSolution() {
  setMetaInfo({.id = 2644,
               .title = "Find the Maximum Divisibility Score",
               .url = "https://leetcode.com/problems/find-the-maximum-divisibility-score/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      maxDivScoreImpl);
}

int FindTheMaximumDivisibilityScoreSolution::maxDivScore(
    std::vector<int>& nums, std::vector<int>& divisors) {
  return getSolution()(nums, divisors);
}

}  // namespace problem_2644
}  // namespace leetcode
