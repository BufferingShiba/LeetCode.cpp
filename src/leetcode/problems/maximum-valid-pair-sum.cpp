#include "leetcode/problems/maximum-valid-pair-sum.h"

#include <algorithm>
#include <limits>

namespace leetcode {
namespace problem_3979 {
namespace {

int prefixMaximumStrategy(std::vector<int>& nums, int k) {
  int bestLeft = nums.front();
  int answer = std::numeric_limits<int>::min();
  for (int right = k; right < static_cast<int>(nums.size()); ++right) {
    bestLeft = std::max(bestLeft, nums[right - k]);
    answer = std::max(answer, bestLeft + nums[right]);
  }
  return answer;
}

}  // namespace

MaximumValidPairSumSolution::MaximumValidPairSumSolution() {
  setMetaInfo({.id = 3979,
               .title = "Maximum Valid Pair Sum",
               .url = "https://leetcode.com/problems/maximum-valid-pair-sum/"});
  registerStrategy(
      {.name = "PrefixMaximum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      prefixMaximumStrategy);
}

}  // namespace problem_3979
}  // namespace leetcode
