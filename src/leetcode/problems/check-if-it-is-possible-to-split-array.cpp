#include "leetcode/problems/check-if-it-is-possible-to-split-array.h"

namespace leetcode {
namespace problem_2811 {

namespace {

bool canSplitArrayImpl(std::vector<int>& nums, int m) {
  const int n = static_cast<int>(nums.size());
  // If n <= 2, we can directly split into single elements.
  if (n <= 2) {
    return true;
  }
  // For n >= 3, it is possible iff there exists an adjacent pair
  // whose sum is at least m (that pair is saved for the final split).
  for (int i = 0; i + 1 < n; ++i) {
    if (nums[i] + nums[i + 1] >= m) {
      return true;
    }
  }
  return false;
}

}  // namespace

CheckIfItIsPossibleToSplitArraySolution::CheckIfItIsPossibleToSplitArraySolution() {
  setMetaInfo({.id = 2811,
               .title = "Check if it is Possible to Split Array",
               .url = "https://leetcode.com/problems/check-if-it-is-possible-to-split-array/"});

  registerStrategy({.name = "greedy_adjacent_pair",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy"}},
                   canSplitArrayImpl);
}

bool CheckIfItIsPossibleToSplitArraySolution::canSplitArray(std::vector<int>& nums, int m) {
  return getSolution()(nums, m);
}

}  // namespace problem_2811
}  // namespace leetcode
