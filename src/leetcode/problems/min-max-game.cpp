#include "leetcode/problems/min-max-game.h"

namespace leetcode {
namespace problem_2293 {

namespace {

int minMaxGameImpl(std::vector<int>& nums) {
  while (nums.size() > 1) {
    std::vector<int> newNums(nums.size() / 2);
    for (int i = 0; i < (int)newNums.size(); ++i) {
      if (i % 2 == 0) {
        newNums[i] = std::min(nums[2 * i], nums[2 * i + 1]);
      } else {
        newNums[i] = std::max(nums[2 * i], nums[2 * i + 1]);
      }
    }
    nums = std::move(newNums);
  }
  return nums[0];
}

}  // namespace

MinMaxGameSolution::MinMaxGameSolution() {
  setMetaInfo({2293, "Min Max Game",
               "https://leetcode.com/problems/min-max-game/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Simulation"}},
                   minMaxGameImpl);
}

int MinMaxGameSolution::minMaxGame(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2293
}  // namespace leetcode
