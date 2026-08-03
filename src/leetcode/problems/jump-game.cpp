#include "leetcode/problems/jump-game.h"

#include <algorithm>

namespace leetcode {
namespace problem_55 {

namespace {

bool canJumpImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int max_reach = 0;
  for (int i = 0; i < n; ++i) {
    if (i > max_reach) {
      return false;
    }
    max_reach = std::max(max_reach, i + nums[i]);
    if (max_reach >= n - 1) {
      return true;
    }
  }
  return true;
}

}  // namespace

JumpGameSolution::JumpGameSolution() {
  setMetaInfo({.id = 55, .title = "Jump Game", .url = "https://leetcode.com/problems/jump-game/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      canJumpImpl);
  setDefaultStrategy();
}

bool JumpGameSolution::canJump(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_55
}  // namespace leetcode
