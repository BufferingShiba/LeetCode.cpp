#include "leetcode/problems/sum-of-integers-with-maximum-digit-range.h"

namespace leetcode::problem_3982 {

namespace {

int maxDigitRangeImpl(std::vector<int>& nums) {
  int maxRange = 0;
  std::vector<int> ranges(nums.size());
  for (size_t i = 0; i < nums.size(); ++i) {
    int n = nums[i];
    int mn = 9, mx = 0;
    while (n > 0) {
      int d = n % 10;
      if (d < mn) mn = d;
      if (d > mx) mx = d;
      n /= 10;
    }
    int r = mx - mn;
    ranges[i] = r;
    if (r > maxRange) maxRange = r;
  }
  int sum = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (ranges[i] == maxRange) sum += nums[i];
  }
  return sum;
}

}  // namespace

int SumOfIntegersWithMaximumDigitRangeSolution::maxDigitRange(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

SumOfIntegersWithMaximumDigitRangeSolution::
    SumOfIntegersWithMaximumDigitRangeSolution() {
  setMetaInfo(
      {.id = 3982,
       .title = "Sum of Integers with Maximum Digit Range",
       .url = "https://leetcode.com/problems/sum-of-integers-with-maximum-"
              "digit-range/"});
  registerStrategy(
      {.name = "two-pass-digit-range",
       .expected = "Accepted",
       .time_complexity = "O(n * d)",
       .space_complexity = "O(n)",
       .tags = {"array", "simulation"}},
      maxDigitRangeImpl);
}

}  // namespace leetcode::problem_3982
