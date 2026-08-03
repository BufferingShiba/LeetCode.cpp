#include "leetcode/problems/minimum-absolute-distance-between-mirror-pairs.h"

#include <unordered_map>

namespace leetcode {
namespace problem_3761 {

namespace {

// 返回 x 的十进制翻转结果（去除前导零）
long long reverseDigits(long long x) {
  long long rev = 0;
  while (x > 0) {
    rev = rev * 10 + x % 10;
    x /= 10;
  }
  return rev;
}

int minMirrorPairDistanceImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  // reverse(nums[i]) -> 最近一次出现的位置 i
  std::unordered_map<long long, int> lastRevIndex;
  int ans = -1;
  for (int j = 0; j < n; ++j) {
    // 找 i<j 满足 reverse(nums[i]) == nums[j]
    // 即查 lastRevIndex[nums[j]]
    auto it = lastRevIndex.find(nums[j]);
    if (it != lastRevIndex.end()) {
      int dist = j - it->second;
      if (ans == -1 || dist < ans) {
        ans = dist;
      }
    }
    // 记录 reverse(nums[j]) 最近出现的位置（贪心：越近越好）
    lastRevIndex[reverseDigits(nums[j])] = j;
  }
  return ans;
}

}  // namespace

MinimumAbsoluteDistanceBetweenMirrorPairsSolution::
    MinimumAbsoluteDistanceBetweenMirrorPairsSolution() {
  setMetaInfo({.id = 3761,
               .title = "Minimum Absolute Distance Between Mirror Pairs",
               .url = "https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/"});
  registerStrategy(
      {.name = "hashmap-nearest",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Math"}},
      minMirrorPairDistanceImpl);
}

int MinimumAbsoluteDistanceBetweenMirrorPairsSolution::minMirrorPairDistance(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3761
}  // namespace leetcode
