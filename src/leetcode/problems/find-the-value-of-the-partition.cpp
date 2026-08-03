
#include "leetcode/problems/find-the-value-of-the-partition.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_2740 {

// 排序 + 相邻差最小值
// 划分后 |max(nums1) - min(nums2)| 对应排序序列中某一对相邻元素之差，
// 故最小值即为所有相邻差的最小值。
// 时间复杂度: O(n log n), 空间复杂度: O(log n)（排序栈）
static int solution1(vector<int>& nums) {
  const int n = nums.size();
  std::sort(nums.begin(), nums.end());
  int best = INT_MAX;
  for (int i = 1; i < n; ++i) {
    best = std::min(best, nums[i] - nums[i - 1]);
  }
  return best;
}

FindTheValueOfThePartitionSolution::FindTheValueOfThePartitionSolution() {
  setMetaInfo({.id = 2740,
               .title = "Find the Value of the Partition",
               .url = "https://leetcode.com/problems/find-the-value-of-the-partition"});
  registerStrategy({.name = "Sort + Min Adjacent Difference",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Array", "Sorting"},
                    .notes =
                        "Sort then minimize adjacent difference; the optimal split always "
                        "separates two adjacent elements in sorted order."},
                   solution1);
}

int FindTheValueOfThePartitionSolution::findValueOfPartition(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2740
}  // namespace leetcode
