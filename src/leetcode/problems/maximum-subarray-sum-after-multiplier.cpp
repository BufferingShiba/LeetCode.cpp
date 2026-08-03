#include "leetcode/problems/maximum-subarray-sum-after-multiplier.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_3976 {

namespace {

long long maxSubarraySumImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());

  long long a0 = nums[0];
  long long dp0 = a0;               // no operation inside sum subarray yet
  long long dp1 = a0 * k;           // currently inside multiply segment
  long long dp2 = a0 / k;           // currently inside divide segment
  long long dp3 = LLONG_MIN / 2;    // operation already finished

  long long ans = std::max({dp0, dp1, dp2});

  for (int i = 1; i < n; ++i) {
    long long a = nums[i];
    long long m = a * k;
    long long d = a / k;

    long long ndp0 = std::max(a, dp0 + a);
    long long ndp1 = std::max({m, dp0 + m, dp1 + m});
    long long ndp2 = std::max({d, dp0 + d, dp2 + d});
    long long ndp3 = std::max({dp1 + a, dp2 + a, dp3 + a});

    ans = std::max({ans, ndp0, ndp1, ndp2, ndp3});

    dp0 = ndp0;
    dp1 = ndp1;
    dp2 = ndp2;
    dp3 = ndp3;
  }

  return ans;
}

}  // namespace

MaximumSubarraySumAfterMultiplierSolution::MaximumSubarraySumAfterMultiplierSolution() {
  setMetaInfo({.id = 3976,
               .title = "Maximum Subarray Sum After Multiplier",
               .url = "https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/"});
  registerStrategy({.name = "Kadane DP with 4 states",
                     .expected = "Accepted",
                     .time_complexity = "O(n)",
                     .space_complexity = "O(1)",
                     .tags = {"Array", "Dynamic Programming"}},
                   maxSubarraySumImpl);

  setDefaultStrategy();
}

long long MaximumSubarraySumAfterMultiplierSolution::maxSubarraySum(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3976
}  // namespace leetcode
