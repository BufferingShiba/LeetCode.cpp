#include "leetcode/problems/number-of-subarrays-that-match-a-pattern-i.h"

namespace leetcode {
namespace problem_3034 {

// Build the relation array rel where rel[j] = sign(nums[j+1] - nums[j])
// (1 if increasing, 0 if equal, -1 if decreasing), then count occurrences of
// the pattern within rel using the KMP string-matching algorithm.
int NumberOfSubarraysThatMatchAPatternISolution::countMatchingSubarraysKmp(
    std::vector<int>& nums, std::vector<int>& pattern) {
  const int n = static_cast<int>(nums.size());
  const int m = static_cast<int>(pattern.size());

  // Build the relation array of length n - 1.
  std::vector<int> rel;
  rel.reserve(n - 1);
  for (int j = 0; j + 1 < n; ++j) {
    if (nums[j + 1] > nums[j]) {
      rel.push_back(1);
    } else if (nums[j + 1] == nums[j]) {
      rel.push_back(0);
    } else {
      rel.push_back(-1);
    }
  }

  // Build the prefix function for the pattern.
  std::vector<int> pi(m, 0);
  for (int i = 1; i < m; ++i) {
    int j = pi[i - 1];
    while (j > 0 && pattern[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      ++j;
    }
    pi[i] = j;
  }

  // Count occurrences of the pattern inside rel.
  int count = 0;
  int j = 0;
  for (int c : rel) {
    while (j > 0 && c != pattern[j]) {
      j = pi[j - 1];
    }
    if (c == pattern[j]) {
      ++j;
    }
    if (j == m) {
      ++count;
      j = pi[j - 1];
    }
  }

  return count;
}

}  // namespace problem_3034
}  // namespace leetcode
