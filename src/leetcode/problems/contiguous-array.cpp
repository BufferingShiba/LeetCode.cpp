#include "leetcode/problems/contiguous-array.h"

#include <unordered_map>

namespace leetcode::problem_525 {

int ContiguousArraySolution::findMaxLengthImpl(std::vector<int>& nums) {
  // 将 0 视为 -1，前缀和相同时中间区间 0 和 1 数量相等。
  std::unordered_map<int, int> firstIndex;
  firstIndex[0] = -1;  // 空前缀的下标
  int prefix = 0;
  int maxLen = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    prefix += (nums[i] == 1) ? 1 : -1;
    auto it = firstIndex.find(prefix);
    if (it != firstIndex.end()) {
      maxLen = std::max(maxLen, i - it->second);
    } else {
      firstIndex[prefix] = i;
    }
  }
  return maxLen;
}

int ContiguousArraySolution::findMaxLength(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_525
