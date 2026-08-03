#include "leetcode/problems/maximum-xor-for-each-query.h"

namespace leetcode::problem_1829 {

namespace {

std::vector<int> getMaximumXorImpl(std::vector<int>& nums, int maximumBit) {
  const int n = static_cast<int>(nums.size());
  const int maxMask = (1 << maximumBit) - 1;
  std::vector<int> ans(n);
  int curr = 0;
  for (int x : nums) {
    curr ^= x;
  }
  for (int i = 0; i < n; ++i) {
    ans[i] = maxMask ^ curr;
    curr ^= nums[n - 1 - i];  // remove last element
  }
  return ans;
}

}  // namespace

MaximumXorForEachQuerySolution::MaximumXorForEachQuerySolution() {
  setMetaInfo({.id = 1829,
               .title = "Maximum XOR for Each Query",
               .url = "https://leetcode.com/problems/maximum-xor-for-each-query/"});
  registerStrategy({.name = "prefix-xor-bitmask",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Bit Manipulation", "Prefix Sum"}},
                   getMaximumXorImpl);
}

std::vector<int> MaximumXorForEachQuerySolution::getMaximumXor(std::vector<int>& nums,
                                                                int maximumBit) {
  return getSolution()(nums, maximumBit);
}

}  // namespace leetcode::problem_1829
