#include <unordered_map>
#include <vector>

#include "leetcode/problems/split-array-with-same-average.h"

namespace leetcode {
namespace problem_805 {
namespace {

// Transform element x into x*n - total_sum. We need a non-empty, non-full
// subset of nums whose transformed sum equals 0. That subset corresponds to
// group A (or B) satisfying average equal condition.
// Use meet-in-the-middle over two halves.
bool splitArraySameAverageImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n < 2) return false;

  int total = 0;
  for (int x : nums) total += x;

  std::vector<int> vals(n);
  for (int i = 0; i < n; ++i) vals[i] = nums[i] * n - total;

  const int m = n / 2;
  const int rightLen = n - m;

  std::vector<std::unordered_map<int, int>> rightSums(rightLen + 1);
  for (int mask = 0; mask < (1 << rightLen); ++mask) {
    int cnt = 0, sum = 0;
    for (int j = 0; j < rightLen; ++j) {
      if (mask & (1 << j)) {
        ++cnt;
        sum += vals[m + j];
      }
    }
    rightSums[cnt][sum] = 1;
  }

  for (int mask = 0; mask < (1 << m); ++mask) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        ++cnt;
        sum += vals[i];
      }
    }
    for (int rc = 0; rc <= rightLen; ++rc) {
      int totalCnt = cnt + rc;
      if (totalCnt == 0 || totalCnt == n) continue;
      if (rightSums[rc].count(-sum)) {
        return true;
      }
    }
  }
  return false;
}

}  // namespace

SplitArrayWithSameAverageSolution::SplitArrayWithSameAverageSolution() {
  setMetaInfo({805, "Split Array With Same Average",
               "https://leetcode.com/problems/split-array-with-same-average/"});
  registerStrategy(
      {"MeetInTheMiddle", "Accepted", "O(2^(n/2) * n/2)", "O(2^(n/2))",
       {"Array", "Hash Table", "Math", "Bit Manipulation", "Bitmask"},
       "Meet-in-the-middle over transformed values x*n - sum."},
      splitArraySameAverageImpl);
}

bool SplitArrayWithSameAverageSolution::splitArraySameAverage(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_805
}  // namespace leetcode
