#include "leetcode/problems/sum-of-all-odd-length-subarrays.h"

namespace leetcode {
namespace problem_1588 {

static int sumOddLengthSubarraysImpl(std::vector<int>& arr) {
  int n = static_cast<int>(arr.size());
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int left = i + 1;
    int right = n - i;
    int odd_count = (left * right + 1) / 2;
    total += arr[i] * odd_count;
  }
  return total;
}

SumOfAllOddLengthSubarraysSolution::SumOfAllOddLengthSubarraysSolution() {
  setMetaInfo({.id = 1588,
               .title = "Sum of All Odd Length Subarrays",
               .url = "https://leetcode.com/problems/sum-of-all-odd-length-subarrays/"});

  registerStrategy(
      {.name = "math",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Prefix Sum"}},
      sumOddLengthSubarraysImpl);
}

int SumOfAllOddLengthSubarraysSolution::sumOddLengthSubarrays(
    std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1588
}  // namespace leetcode
