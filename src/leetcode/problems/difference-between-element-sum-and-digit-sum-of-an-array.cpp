#include "leetcode/problems/difference-between-element-sum-and-digit-sum-of-an-array.h"

namespace leetcode {
namespace problem_2535 {

namespace {

int differenceOfSumImpl(std::vector<int>& nums) {
  int element_sum = 0;
  int digit_sum = 0;
  for (int x : nums) {
    element_sum += x;
    while (x > 0) {
      digit_sum += x % 10;
      x /= 10;
    }
  }
  return std::abs(element_sum - digit_sum);
}

}  // namespace

int DifferenceBetweenElementSumAndDigitSumOfAnArraySolution::differenceOfSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

// Register the strategy in the constructor so every instance is self-contained.
DifferenceBetweenElementSumAndDigitSumOfAnArraySolution::
    DifferenceBetweenElementSumAndDigitSumOfAnArraySolution() {
  setMetaInfo({.id = 2535,
               .title = "Difference Between Element Sum and Digit Sum of an Array",
               .url = "https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/"});
  registerStrategy(
      {"SinglePass", "Accepted", "O(n)", "O(1)", {"Array", "Math"}},
      [](std::vector<int>& nums) { return differenceOfSumImpl(nums); });
}

}  // namespace problem_2535
}  // namespace leetcode
