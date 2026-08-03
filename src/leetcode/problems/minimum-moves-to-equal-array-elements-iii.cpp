#include "leetcode/problems/minimum-moves-to-equal-array-elements-iii.h"

namespace leetcode {
namespace problem_3736 {
namespace {

int minMovesImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int sum = 0;
  int maxVal = 1;  // constraints: nums[i] >= 1
  for (int x : nums) {
    sum += x;
    if (x > maxVal) maxVal = x;
  }
  return maxVal * n - sum;
}

}  // namespace

MinimumMovesToEqualArrayElementsIiiSolution::MinimumMovesToEqualArrayElementsIiiSolution() {
  setMetaInfo({3736, "Minimum Moves to Equal Array Elements III", "https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/"});
  registerStrategy({.name = "RaiseToMax",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},
                   minMovesImpl);
}

int MinimumMovesToEqualArrayElementsIiiSolution::minMoves(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3736
}  // namespace leetcode
