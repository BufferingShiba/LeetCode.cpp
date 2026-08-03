#include "leetcode/problems/maximize-cyclic-partition-score.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3743 {

namespace {

long long maximumScoreImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());

  // maximum number of non-trivial segments (length >= 2)
  int max_segments = std::min(k, n / 2);

  long long ans = 0;
  long long sum_top = 0;
  long long sum_bottom = 0;

  for (int c = 1; c <= max_segments; ++c) {
    sum_top += nums[n - c];       // c-th largest
    sum_bottom += nums[c - 1];    // c-th smallest
    long long score = sum_top - sum_bottom;
    if (score > ans) {
      ans = score;
    }
  }

  return ans;
}

}  // namespace

MaximizeCyclicPartitionScoreSolution::MaximizeCyclicPartitionScoreSolution() {
  setMetaInfo({.id = 3743,
               .title = "Maximize Cyclic Partition Score",
               .url = "https://leetcode.com/problems/maximize-cyclic-partition-score/"});

  registerStrategy(
      {.name = "greedy_top_bottom_pairs",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      maximumScoreImpl);
}

long long MaximizeCyclicPartitionScoreSolution::maximumScore(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3743
}  // namespace leetcode
