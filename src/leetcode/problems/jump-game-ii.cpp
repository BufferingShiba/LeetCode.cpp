#include "leetcode/problems/jump-game-ii.h"

namespace leetcode {
namespace problem_45 {

namespace {

int jumpImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int jumps = 0;
  int currEnd = 0;
  int farthest = 0;
  for (int i = 0; i < n - 1; ++i) {
    farthest = std::max(farthest, i + nums[i]);
    if (i == currEnd) {
      ++jumps;
      currEnd = farthest;
    }
  }
  return jumps;
}

}  // namespace

JumpGameIiSolution::JumpGameIiSolution() {
  setMetaInfo({.id = 45,
               .title = "Jump Game II",
               .url = "https://leetcode.com/problems/jump-game-ii/"});
  registerStrategy({.name = "GreedyBFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Greedy", "Array"}},
                   jumpImpl);
}

int JumpGameIiSolution::jump(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_45
}  // namespace leetcode
