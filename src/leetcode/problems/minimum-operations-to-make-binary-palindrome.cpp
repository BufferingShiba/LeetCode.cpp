#include "leetcode/problems/minimum-operations-to-make-binary-palindrome.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3766 {

namespace {

// Generate all binary palindrome integers up to 2^maxBits - 1.
// A binary palindrome has a binary representation (no leading zeros)
// that reads the same forward and backward.
std::vector<int> generateBinaryPalindromes(int maxBits) {
  std::vector<int> pals;
  // length 1: only "1"
  pals.push_back(1);
  // length 2: only "11"
  pals.push_back(3);

  for (int L = 3; L <= maxBits; ++L) {
    int halfLen = (L + 1) / 2;  // ceil(L/2)
    int halfCount = 1 << (halfLen - 1);
    for (int h = 0; h < halfCount; ++h) {
      int half = (1 << (halfLen - 1)) | h;
      int val = half;
      // Mirror bits from LSB to MSB, skipping the middle bit for odd L
      int start = (L % 2 == 1) ? 1 : 0;
      for (int i = start; i < halfLen; ++i) {
        val = (val << 1) | ((half >> i) & 1);
      }
      pals.push_back(val);
    }
  }

  std::sort(pals.begin(), pals.end());
  return pals;
}

std::vector<int> minOperationsImpl(std::vector<int>& nums) {
  // Generate all binary palindromes up to 15 bits (max ~32768),
  // which is more than enough for nums[i] <= 5000.
  static const std::vector<int> pals = generateBinaryPalindromes(15);

  std::vector<int> ans;
  ans.reserve(nums.size());

  for (int num : nums) {
    auto it = std::lower_bound(pals.begin(), pals.end(), num);
    int best = INT_MAX;
    if (it != pals.end()) {
      best = std::min(best, *it - num);
    }
    if (it != pals.begin()) {
      best = std::min(best, num - *std::prev(it));
    }
    ans.push_back(best);
  }

  return ans;
}

}  // namespace

MinimumOperationsToMakeBinaryPalindromeSolution::MinimumOperationsToMakeBinaryPalindromeSolution() {
  setMetaInfo({.id = 3766,
               .title = "Minimum Operations to Make Binary Palindrome",
               .url = "https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/"});
  registerStrategy({.name = "PrecomputeBinaryPalindromes",
                    .expected = "Accepted",
                    .time_complexity = "O(maxVal + N log K)",
                    .space_complexity = "O(K + N)",
                    .tags = {"Array", "Binary Search", "Bit Manipulation", "Two Pointers"}},
                   minOperationsImpl);
  setDefaultStrategy();
}

std::vector<int> MinimumOperationsToMakeBinaryPalindromeSolution::minOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3766
