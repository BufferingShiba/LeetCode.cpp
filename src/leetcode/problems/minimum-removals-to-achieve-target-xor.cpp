#include "leetcode/problems/minimum-removals-to-achieve-target-xor.h"

#include <algorithm>
#include <optional>
#include <unordered_map>
#include <utility>

namespace leetcode::problem_3877 {

namespace {

// 枚举子集，返回 {xor_value -> 最少的子集大小}
// 对给定索引范围 [l, r) 的元素，枚举所有子集，对每个 xor 值记录能达到它的最小 |子集|
void enumerateSubsets(const std::vector<int>& nums, int l, int r,
                      std::unordered_map<int, int>& best) {
  int len = r - l;
  // 枚举所有子集，用二进制掩码。为避免 2^len 过大，len <= 20
  for (int mask = 0; mask < (1 << len); ++mask) {
    int xval = 0;
    int cnt = __builtin_popcount(static_cast<unsigned>(mask));
    for (int i = 0; i < len; ++i) {
      if (mask & (1 << i)) {
        xval ^= nums[l + i];
      }
    }
    auto it = best.find(xval);
    if (it == best.end() || cnt < it->second) {
      best[xval] = cnt;
    }
  }
}

// 返回在 nums 中，能构成 XOR == need 的最少元素个数；不可能则返回 -1
int minElementsForXor(const std::vector<int>& nums, int need) {
  const int n = static_cast<int>(nums.size());
  const int mid = n / 2;

  std::unordered_map<int, int> leftBest;   // 左半子集的 xor -> 最小 size
  std::unordered_map<int, int> rightBest;  // 右半子集的 xor -> 最小 size

  enumerateSubsets(nums, 0, mid, leftBest);
  enumerateSubsets(nums, mid, n, rightBest);

  int answer = -1;
  for (const auto& [rXor, rCnt] : rightBest) {
    int needLeft = need ^ rXor;
    auto itLeft = leftBest.find(needLeft);
    if (itLeft != leftBest.end()) {
      int total = itLeft->second + rCnt;
      if (answer < 0 || total < answer) {
        answer = total;
      }
    }
  }
  return answer;
}

int minRemovalsImpl(std::vector<int>& nums, int target) {
  int total = 0;
  for (int v : nums) {
    total ^= v;
  }
  // 需要被移除的子集 XOR == total XOR target
  int need = total ^ target;
  int minRemoved = minElementsForXor(nums, need);
  return minRemoved;
}

}  // namespace

MinimumRemovalsToAchieveTargetXorSolution::
    MinimumRemovalsToAchieveTargetXorSolution() {
  setMetaInfo({.id = 3877,
               .title = "Minimum Removals to Achieve Target XOR",
               .url = "https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/"});
  registerStrategy(
      {.name = "meet_in_the_middle",
       .expected = "Accepted",
       .time_complexity = "O(2^(n/2))",
       .space_complexity = "O(2^(n/2))",
       .tags = {"Array", "Dynamic Programming", "Bit Manipulation"}},
      static_cast<Func>(minRemovalsImpl));
}

int MinimumRemovalsToAchieveTargetXorSolution::minRemovals(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace leetcode::problem_3877
