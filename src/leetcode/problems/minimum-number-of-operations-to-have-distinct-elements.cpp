#include "leetcode/problems/minimum-number-of-operations-to-have-distinct-elements.h"

#include <unordered_set>

namespace leetcode::problem_3779 {

static int minOperationsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::unordered_set<int> seen;
  int i = n;  // 第一个需要被删除的位置（从该位置开始的后缀无重复）
  for (int j = n - 1; j >= 0; --j) {
    if (seen.count(nums[j])) {
      // nums[j] 与后面某个元素重复，必须删除到 j+1
      i = j + 1;
      break;
    }
    seen.insert(nums[j]);
  }
  // 如果整个数组无重复，i 保持为 0（因为循环未 break，需要设 i=0）
  if (i == n) {
    i = 0;
  }
  // 最少操作次数 = ceil(i / 3)
  return (i + 2) / 3;
}

MinimumNumberOfOperationsToHaveDistinctElementsSolution::
    MinimumNumberOfOperationsToHaveDistinctElementsSolution() {
  setMetaInfo({.id = 3779,
               .title = "Minimum Number of Operations to Have Distinct Elements",
               .url = "https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/"});
  registerStrategy(
      {.name = "RightToLeftScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      minOperationsImpl);
}

int MinimumNumberOfOperationsToHaveDistinctElementsSolution::minOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3779
