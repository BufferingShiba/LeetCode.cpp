#include <algorithm>
#include <vector>

#include "leetcode/problems/minimum-sum-of-four-digit-number-after-splitting-digits.h"

namespace leetcode {
namespace problem_2160 {

namespace {

int minimumSumImpl(int num) {
  std::vector<int> digits;
  while (num > 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  std::sort(digits.begin(), digits.end());
  // 贪心：最小的两个数字放十位，较大的放个位
  return (digits[0] * 10 + digits[2]) + (digits[1] * 10 + digits[3]);
}

}  // namespace

int MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution::minimumSum(int num) {
  return getSolution()(num);
}

MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution::
    MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution() {
  setMetaInfo({.id = 2160,
               .title = "Minimum Sum of Four Digit Number After Splitting Digits",
               .url = "https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Greedy", "Sorting"}},
      minimumSumImpl);
}

}  // namespace problem_2160
}  // namespace leetcode
