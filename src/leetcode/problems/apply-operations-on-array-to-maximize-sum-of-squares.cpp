#include "leetcode/problems/apply-operations-on-array-to-maximize-sum-of-squares.h"

#include <algorithm>

namespace leetcode::problem_2897 {

namespace {

// The AND/OR operation preserves the total number of 1-bits for every bit
// position across the whole array. By an exchange argument, to maximize the
// sum of squares of the chosen numbers, we concentrate every bit onto the
// largest (fewest) numbers. So: for each bit, give its (up to k) copies to
// result[0..min(cnt,k)-1].
int maxSumImpl(std::vector<int>& nums, int k) {
  constexpr long long kMod = 1000000007LL;
  int bitcnt[32] = {0};
  for (int x : nums) {
    for (int b = 0; b < 32; ++b) {
      if ((x >> b) & 1) {
        ++bitcnt[b];
      }
    }
  }

  std::vector<long long> res(k, 0);
  for (int b = 0; b < 32; ++b) {
    int take = std::min(bitcnt[b], k);
    long long bit = 1LL << b;
    for (int i = 0; i < take; ++i) {
      res[i] += bit;
    }
  }

  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    long long v = res[i] % kMod;
    ans = (ans + v * v) % kMod;
  }
  return static_cast<int>(ans);
}

}  // namespace

int ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution::maxSum(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution::
    ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution() {
  setMetaInfo({.id = 2897,
               .title =
                   "Apply Operations on Array to Maximize Sum of Squares",
               .url =
                   "https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/"});
  registerStrategy(
      {.name = "greedy_bit_distribution",
       .expected = "Accepted",
       .time_complexity = "O((n + k) * 32)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Hash Table", "Greedy", "Bit Manipulation"}},
      maxSumImpl);
}

}  // namespace leetcode::problem_2897
