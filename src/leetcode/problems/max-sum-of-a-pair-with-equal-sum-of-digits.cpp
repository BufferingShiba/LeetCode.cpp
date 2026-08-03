#include "leetcode/problems/max-sum-of-a-pair-with-equal-sum-of-digits.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_2342 {

namespace {

constexpr int kMaxDigitSum = 81;  // 999,999,999 -> 9*9 = 81

int digitSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int maximumSumImpl(std::vector<int>& nums) {
  // maxNum[ds] = 当前遇到数位和为 ds 的最大数，0 表示尚未遇到
  int maxNum[kMaxDigitSum + 1] = {0};
  int ans = -1;

  for (int num : nums) {
    int ds = digitSum(num);
    if (maxNum[ds] != 0) {
      ans = std::max(ans, maxNum[ds] + num);
    }
    if (num > maxNum[ds]) {
      maxNum[ds] = num;
    }
  }

  return ans;
}

}  // namespace

MaxSumOfAPairWithEqualSumOfDigitsSolution::
    MaxSumOfAPairWithEqualSumOfDigitsSolution() {
  setMetaInfo({.id = 2342,
               .title = "Max Sum of a Pair With Equal Sum of Digits",
               .url = "https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/"});

  registerStrategy(
      {.name = "Hash Table (Array) One Pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Sorting", "Heap (Priority Queue)"}},
      maximumSumImpl);

  setDefaultStrategy();
}

int MaxSumOfAPairWithEqualSumOfDigitsSolution::maximumSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2342
}  // namespace leetcode
