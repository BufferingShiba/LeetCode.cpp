#include "leetcode/problems/minimum-operations-to-collect-elements.h"

namespace leetcode {
namespace problem_2869 {

namespace {

int minOperationsImpl(std::vector<int>& nums, int k) {
  std::vector<bool> collected(k + 1, false);
  int cnt = 0;
  for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
    int v = nums[i];
    if (v >= 1 && v <= k && !collected[v]) {
      collected[v] = true;
      ++cnt;
      if (cnt == k) {
        return static_cast<int>(nums.size()) - i;
      }
    }
  }
  return static_cast<int>(nums.size());
}

}  // namespace

MinimumOperationsToCollectElementsSolution::MinimumOperationsToCollectElementsSolution() {
  setMetaInfo({.id = 2869,
               .title = "Minimum Operations to Collect Elements",
               .url = "https://leetcode.com/problems/minimum-operations-to-collect-elements/"});

  registerStrategy({.name = "greedy-backward",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(k)",
                    .tags = {"Array", "Hash Table"}},
                   minOperationsImpl);
}

int MinimumOperationsToCollectElementsSolution::minOperations(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2869
}  // namespace leetcode
