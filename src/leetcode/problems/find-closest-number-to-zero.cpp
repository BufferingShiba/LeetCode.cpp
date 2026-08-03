#include "leetcode/problems/find-closest-number-to-zero.h"

#include <vector>

namespace leetcode {
namespace problem_2239 {

namespace {

int findClosestNumberImpl(std::vector<int>& nums) {
  int result = nums[0];
  for (int num : nums) {
    if (std::abs(num) < std::abs(result) ||
        (std::abs(num) == std::abs(result) && num > result)) {
      result = num;
    }
  }
  return result;
}

}  // namespace

FindClosestNumberToZeroSolution::FindClosestNumberToZeroSolution() {
  setMetaInfo({.id = 2239,
               .title = "Find Closest Number to Zero",
               .url = "https://leetcode.com/problems/find-closest-number-to-zero/"});

  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      findClosestNumberImpl);
}

int FindClosestNumberToZeroSolution::findClosestNumber(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2239
}  // namespace leetcode
