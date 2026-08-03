#include "leetcode/problems/move-zeroes.h"

namespace leetcode {
namespace problem_283 {

namespace {

void moveZeroesImpl(std::vector<int>& nums) {
  int insertPos = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] != 0) {
      std::swap(nums[insertPos], nums[i]);
      ++insertPos;
    }
  }
}

}  // namespace

MoveZeroesSolution::MoveZeroesSolution() {
  setMetaInfo({.id = 283, .title = "Move Zeroes", .url = "https://leetcode.com/problems/move-zeroes/"});
  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      moveZeroesImpl);
}

void MoveZeroesSolution::moveZeroes(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_283
}  // namespace leetcode
