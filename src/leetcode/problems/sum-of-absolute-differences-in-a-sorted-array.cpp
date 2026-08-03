#include "leetcode/problems/sum-of-absolute-differences-in-a-sorted-array.h"

namespace leetcode {
namespace problem_1685 {

namespace {

// 前缀和策略：利用数组已排序，对每个下标 i，
// 左边元素均 <= nums[i]，右边元素均 >= nums[i]，
// 从而去掉绝对值符号后可用前缀和 O(1) 计算每个答案。
std::vector<int> prefix_sum_strategy(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  // total = 全部元素之和
  long long total = 0;
  for (int x : nums) total += x;

  std::vector<int> result(n, 0);
  long long left_sum = 0;  // 当前 i 左边元素之和
  for (int i = 0; i < n; ++i) {
    // 左边贡献: nums[i] - nums[j] for j < i
    long long left = 1LL * i * nums[i] - left_sum;
    // 右边贡献: nums[j] - nums[i] for j > i
    long long right = (total - left_sum - nums[i]) - 1LL * (n - 1 - i) * nums[i];
    result[i] = static_cast<int>(left + right);
    left_sum += nums[i];
  }
  return result;
}

}  // namespace

SumOfAbsoluteDifferencesInASortedArraySolution::
    SumOfAbsoluteDifferencesInASortedArraySolution() {
  setMetaInfo({.id = 1685,
               .title = "Sum of Absolute Differences in a Sorted Array",
               .url = "https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/"});

  registerStrategy(
      {.name = "prefix_sum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Prefix Sum"},
       .notes = "利用有序性去绝对值，结合前缀和累计左边和，O(1) 推每个答案。"},
      prefix_sum_strategy);
}

}  // namespace problem_1685
}  // namespace leetcode
