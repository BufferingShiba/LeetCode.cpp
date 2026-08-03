#include "leetcode/problems/number-of-zero-filled-subarrays.h"

namespace leetcode {
namespace problem_2348 {
namespace {

long long zeroFilledSubarrayImpl(std::vector<int>& nums) {
  long long total = 0;
  long long cnt = 0;  // 当前连续零的长度
  for (int x : nums) {
    if (x == 0) {
      ++cnt;
    } else {
      total += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
  }
  total += cnt * (cnt + 1) / 2;
  return total;
}

}  // namespace

NumberOfZeroFilledSubarraysSolution::NumberOfZeroFilledSubarraysSolution() {
  setMetaInfo({.id = 2348,
               .title = "Number of Zero-Filled Subarrays",
               .url = "https://leetcode.com/problems/number-of-zero-filled-subarrays/"});
  registerStrategy(
      {.name = "counting", .expected = "Accepted", .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      zeroFilledSubarrayImpl);
}

long long NumberOfZeroFilledSubarraysSolution::zeroFilledSubarray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2348
}  // namespace leetcode
