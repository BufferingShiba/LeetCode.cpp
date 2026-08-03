#include "leetcode/problems/maximum-bitwise-and-after-increment-operations.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3806 {
namespace {

// Smallest t >= v such that (t & mask) == mask (t is a superset of mask).
int64_t NextSuperset(int64_t v, int64_t mask) {
  if ((v & mask) == mask) {
    return v;
  }
  // Highest bit where mask has 1 but v has 0.
  int i = -1;
  int64_t missing = mask & ~v;
  for (int b = 60; b >= 0; --b) {
    if ((missing >> b) & 1LL) {
      i = b;
      break;
    }
  }
  int64_t highMask = ~((1LL << (i + 1)) - 1);
  int64_t lowMask = (1LL << i) - 1;
  return (v & highMask) | (1LL << i) | (mask & lowMask);
}

bool Feasible(const std::vector<int64_t>& nums, int64_t cand, int m, int64_t k) {
  std::vector<int64_t> costs;
  costs.reserve(nums.size());
  for (int64_t v : nums) {
    costs.push_back(NextSuperset(v, cand) - v);
  }
  std::sort(costs.begin(), costs.end());
  int64_t sum = 0;
  for (int i = 0; i < m; ++i) {
    sum += costs[i];
  }
  return sum <= k;
}

int MaximumAND(std::vector<int>& nums, int k, int m) {
  std::vector<int64_t> numsLL(nums.begin(), nums.end());
  int64_t ans = 0;
  const int64_t kk = k;
  for (int bit = 30; bit >= 0; --bit) {
    int64_t cand = ans | (1LL << bit);
    if (Feasible(numsLL, cand, m, kk)) {
      ans = cand;
    }
  }
  return static_cast<int>(ans);
}

}  // namespace

MaximumBitwiseAndAfterIncrementOperationsSolution::
    MaximumBitwiseAndAfterIncrementOperationsSolution() {
  setMetaInfo({.id = 3806,
               .title = "Maximum Bitwise AND After Increment Operations",
               .url =
                   "https://leetcode.com/problems/"
                   "maximum-bitwise-and-after-increment-operations/"});
  registerStrategy(
      {.name = "GreedyBit",
       .expected = "Accepted",
       .time_complexity = "O(B * n log n)",
       .space_complexity = "O(n)",
       .tags = {"Bit Manipulation", "Greedy", "Sorting"},
       .notes = "Build answer bit by bit from high to low; feasibility checks "
                "whether m cheapest increments (each to the smallest superset "
                "of the candidate mask) fit within k."},
      MaximumAND);
}

int MaximumBitwiseAndAfterIncrementOperationsSolution::maximumAND(
    std::vector<int>& nums, int k, int m) {
  return getSolution()(nums, k, m);
}

}  // namespace problem_3806
}  // namespace leetcode
