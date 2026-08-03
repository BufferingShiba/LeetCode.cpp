#include "leetcode/problems/set-mismatch.h"

#include <vector>

namespace leetcode {
namespace problem_645 {
namespace {

std::vector<int> findErrorNumsImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<bool> seen(n, false);
  int duplicate = 0;
  for (int x : nums) {
    if (seen[x - 1]) {
      duplicate = x;
    }
    seen[x - 1] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!seen[i - 1]) {
      return {duplicate, i};
    }
  }
  return {duplicate, 0};
}

}  // namespace

SetMismatchSolution::SetMismatchSolution() {
  setMetaInfo({.id = 645,
               .title = "Set Mismatch",
               .url = "https://leetcode.com/problems/set-mismatch/"});
  registerStrategy(
      {.name = "marking",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      findErrorNumsImpl);
}

std::vector<int> SetMismatchSolution::findErrorNums(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_645
}  // namespace leetcode
