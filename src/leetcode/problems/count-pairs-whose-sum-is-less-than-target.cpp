#include "leetcode/problems/count-pairs-whose-sum-is-less-than-target.h"

#include <vector>

namespace leetcode {
namespace problem_2824 {
namespace {

int countPairsImpl(std::vector<int>& nums, int target) {
  const int n = static_cast<int>(nums.size());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] < target) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

CountPairsWhoseSumIsLessThanTargetSolution::CountPairsWhoseSumIsLessThanTargetSolution() {
  setMetaInfo({.id = 2824,
               .title = "Count Pairs Whose Sum is Less than Target",
               .url = "https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/"});
  registerStrategy({.name = "BruteForce",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Enumerate"}},
                   countPairsImpl);
}

int CountPairsWhoseSumIsLessThanTargetSolution::countPairs(std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_2824
}  // namespace leetcode
