#include "leetcode/problems/minimum-sum-of-mountain-triplets-ii.h"

#include <algorithm>
#include <limits>

namespace leetcode {
namespace problem_2909 {

namespace {

int minimumSumImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  const int INF = std::numeric_limits<int>::max();

  std::vector<int> leftMin(n, INF);
  for (int i = 1; i < n; ++i) {
    leftMin[i] = std::min(leftMin[i - 1], nums[i - 1]);
  }

  std::vector<int> rightMin(n, INF);
  for (int i = n - 2; i >= 0; --i) {
    rightMin[i] = std::min(rightMin[i + 1], nums[i + 1]);
  }

  int best = INF;
  for (int j = 1; j + 1 < n; ++j) {
    if (leftMin[j] < nums[j] && rightMin[j] < nums[j]) {
      best = std::min(best, leftMin[j] + nums[j] + rightMin[j]);
    }
  }

  return best == INF ? -1 : best;
}

}  // namespace

MinimumSumOfMountainTripletsIiSolution::MinimumSumOfMountainTripletsIiSolution() {
  setMetaInfo({.id = 2909,
               .title = "Minimum Sum of Mountain Triplets II",
               .url = "https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/"});
  registerStrategy({.name = "PrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Prefix Sum"}},
                   minimumSumImpl);
}

int MinimumSumOfMountainTripletsIiSolution::minimumSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2909
}  // namespace leetcode
