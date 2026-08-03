#include "leetcode/problems/next-greater-numerically-balanced-number.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_2048 {

namespace {

const std::vector<int>& getBalancedNumbers() {
  static const std::vector<int> nums = []() {
    std::vector<int> result;
    // Enumerate non-empty subsets of digits {1..9}.
    // To keep generation tractable, only consider subsets whose digit sum
    // (i.e. the total length of the number) is at most 9.  This covers all
    // lengths up to 9, which is far more than needed for n ≤ 10^6.
    for (int mask = 1; mask < (1 << 9); ++mask) {
      std::string digits;
      int sum = 0;
      for (int d = 1; d <= 9; ++d) {
        if (mask & (1 << (d - 1))) {
          digits.append(d, static_cast<char>('0' + d));
          sum += d;
        }
      }
      if (sum > 9) continue;

      // Generate all unique permutations of the multi-set.
      std::sort(digits.begin(), digits.end());
      do {
        result.push_back(std::stoi(digits));
      } while (std::next_permutation(digits.begin(), digits.end()));
    }
    std::sort(result.begin(), result.end());
    return result;
  }();
  return nums;
}

int nextBeautifulNumberImpl(int n) {
  const auto& nums = getBalancedNumbers();
  auto it = std::upper_bound(nums.begin(), nums.end(), n);
  return *it;
}

}  // namespace

NextGreaterNumericallyBalancedNumberSolution::NextGreaterNumericallyBalancedNumberSolution() {
  setMetaInfo({.id = 2048,
               .title = "Next Greater Numerically Balanced Number",
               .url = "https://leetcode.com/problems/next-greater-numerically-balanced-number/"});
  registerStrategy({.name = "Precompute & Binary Search",
                    .expected = "Accepted",
                    .time_complexity = "O(K log K + log K)",
                    .space_complexity = "O(K)",
                    .tags = {"Hash Table", "Math", "Backtracking", "Counting", "Enumeration"}},
                   nextBeautifulNumberImpl);
}

int NextGreaterNumericallyBalancedNumberSolution::nextBeautifulNumber(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2048
