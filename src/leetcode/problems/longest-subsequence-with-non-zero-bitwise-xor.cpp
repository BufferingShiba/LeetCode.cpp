#include "leetcode/problems/longest-subsequence-with-non-zero-bitwise-xor.h"

namespace leetcode {
namespace problem_3702 {

namespace {

int longestSubsequenceXor(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int total_xor = 0;
  bool has_nonzero = false;
  for (int num : nums) {
    total_xor ^= num;
    if (num != 0) has_nonzero = true;
  }

  if (total_xor != 0) {
    return n;
  }

  // total_xor == 0
  if (has_nonzero) {
    // Remove one non-zero element; the XOR of the rest becomes that element (non-zero).
    return n - 1;
  }

  // All elements are zero -> every subsequence XORs to zero.
  return 0;
}

}  // namespace

LongestSubsequenceWithNonZeroBitwiseXorSolution::
    LongestSubsequenceWithNonZeroBitwiseXorSolution() {
  setMetaInfo({.id = 3702,
               .title = "Longest Subsequence With Non-Zero Bitwise XOR",
               .url = "https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/"});

  registerStrategy({.name = "TotalXorCaseAnalysis",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation", "Greedy"},
                    .notes =
                        "If total XOR is non-zero, answer is n. Otherwise if any "
                        "element is non-zero, drop it (the rest XOR equals it, non-zero) "
                        "giving n-1. If all are zero, answer 0."},
               longestSubsequenceXor);
}

int LongestSubsequenceWithNonZeroBitwiseXorSolution::longestSubsequence(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3702
}  // namespace leetcode
