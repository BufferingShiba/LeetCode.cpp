#include "leetcode/problems/maximum-good-subarray-sum.h"

#include <limits>
#include <unordered_map>

namespace leetcode::problem_3026 {

namespace {

long long maximumSubarraySumImpl(std::vector<int>& nums, int k) {
  const long long kNegInf = std::numeric_limits<long long>::min();
  const int n = static_cast<int>(nums.size());

  // prefix[i] = sum of nums[0..i-1]
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + static_cast<long long>(nums[i]);
  }

  // For each distinct start value v, store the minimum prefix index prefix[i]
  // among all positions i whose element value is v (used as the subarray start).
  std::unordered_map<int, long long> minPrefix;

  long long best = kNegInf;
  for (int j = 0; j < n; ++j) {
    // Subarray nums[i..j] is good when nums[i] == nums[j] +/- k.
    auto consider = [&](int target) {
      auto it = minPrefix.find(target);
      if (it != minPrefix.end()) {
        best = std::max(best, prefix[j + 1] - it->second);
      }
    };
    consider(nums[j] - k);
    consider(nums[j] + k);

    // Now update the best start prefix for value nums[j].
    long long cur = prefix[j];
    auto it = minPrefix.find(nums[j]);
    if (it == minPrefix.end() || cur < it->second) {
      minPrefix[nums[j]] = cur;
    }
  }

  return best == kNegInf ? 0 : best;
}

}  // namespace

MaximumGoodSubarraySumSolution::MaximumGoodSubarraySumSolution() {
  setMetaInfo({.id = 3026,
               .title = "Maximum Good Subarray Sum",
               .url = "https://leetcode.com/problems/maximum-good-subarray-sum/"});
  registerStrategy(
      {.name = "prefix_sum_hashmap",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      maximumSubarraySumImpl);
}

long long MaximumGoodSubarraySumSolution::maximumSubarraySum(std::vector<int>& nums,
                                                             int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3026
