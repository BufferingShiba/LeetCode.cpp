#include "leetcode/problems/reverse-subarray-to-maximize-array-value.h"

#include <algorithm>
#include <cstdlib>
#include <limits>

namespace leetcode {
namespace problem_1330 {

namespace {

int maxValueAfterReverseImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  long long orig = 0;
  for (int i = 0; i + 1 < n; ++i) {
    orig += static_cast<long long>(std::abs(nums[i] - nums[i + 1]));
  }

  long long ans = orig;

  // 情况1: 反转从 index 0 开始的子数组 [0..r], r >= 1
  for (int r = 1; r < n; ++r) {
    long long gain = -static_cast<long long>(std::abs(nums[0] - nums[1]));
    if (r + 1 < n) gain -= std::abs(nums[r] - nums[r + 1]);
    gain += std::abs(nums[r] - nums[1]);
    if (r + 1 < n) gain += std::abs(nums[0] - nums[r + 1]);
    ans = std::max(ans, orig + gain);
  }

  // 情况2: 反转以 index n-1 结尾的子数组 [l..n-1], l <= n-2
  for (int l = 0; l + 1 < n; ++l) {
    long long gain = -static_cast<long long>(std::abs(nums[n - 1] - nums[n - 2]));
    if (l - 1 >= 0) gain -= std::abs(nums[l - 1] - nums[l]);
    gain += std::abs(nums[l] - nums[n - 2]);
    if (l - 1 >= 0) gain += std::abs(nums[l - 1] - nums[n - 1]);
    ans = std::max(ans, orig + gain);
  }

  // 情况3: 内部反转 [l, r], 1 <= l < r <= n-2
  // f = |a-c|+|b-d|-|a-b|-|c-d|
  //   = max_{s,t in {±1}} [ (s*a + t*b - |a-b|) + (-s*c - t*d - |c-d|) ]
  // 其中 a=nums[l-1], b=nums[l], c=nums[r], d=nums[r+1]
  for (int s = -1; s <= 1; s += 2) {
    for (int t = -1; t <= 1; t += 2) {
      long long bestLeft = std::numeric_limits<long long>::min();
      for (int r = 1; r + 1 < n; ++r) {
        // 先纳入 l = r-1 作为左端点候选，保证 l < r
        const int l = r - 1;
        if (l >= 1 && l + 1 < n) {  // 需要 nums[l-1] 存在 且 l <= n-2
          long long leftV =
              static_cast<long long>(s) * nums[l - 1] +
              static_cast<long long>(t) * nums[l] -
              std::abs(nums[l - 1] - nums[l]);
          bestLeft = std::max(bestLeft, leftV);
        }
        long long rightV =
            -static_cast<long long>(s) * nums[r] -
            static_cast<long long>(t) * nums[r + 1] -
            std::abs(nums[r] - nums[r + 1]);
        if (bestLeft != std::numeric_limits<long long>::min()) {
          ans = std::max(ans, orig + bestLeft + rightV);
        }
      }
    }
  }

  return static_cast<int>(ans);
}

}  // namespace

ReverseSubarrayToMaximizeArrayValueSolution::
    ReverseSubarrayToMaximizeArrayValueSolution() {
  setMetaInfo({.id = 1330,
               .title = "Reverse Subarray To Maximize Array Value",
               .url = "https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Greedy"}},
      maxValueAfterReverseImpl);
}

int ReverseSubarrayToMaximizeArrayValueSolution::maxValueAfterReverse(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1330
}  // namespace leetcode
