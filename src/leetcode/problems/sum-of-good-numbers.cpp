#include <functional>

#include "leetcode/problems/sum-of-good-numbers.h"

namespace leetcode::problem_3452 {

namespace {

int sumOfGoodNumbersImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    bool good = true;
    if (i - k >= 0 && nums[i] <= nums[i - k]) {
      good = false;
    }
    if (i + k < n && nums[i] <= nums[i + k]) {
      good = false;
    }
    if (good) {
      sum += nums[i];
    }
  }
  return sum;
}

}  // namespace

SumOfGoodNumbersSolution::SumOfGoodNumbersSolution() {
  setMetaInfo({.id = 3452,
               .title = "Sum of Good Numbers",
               .url = "https://leetcode.com/problems/sum-of-good-numbers/"});

  registerStrategy(
      {.name = "single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"},
       .notes = "For each i, check strictly greater than neighbors at i-k and i+k if they exist."},
      [](std::vector<int>& nums, int k) -> int {
        return sumOfGoodNumbersImpl(nums, k);
      });
}

int SumOfGoodNumbersSolution::sumOfGoodNumbers(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3452
