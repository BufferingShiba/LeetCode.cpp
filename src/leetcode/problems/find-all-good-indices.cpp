#include "leetcode/problems/find-all-good-indices.h"

#include <vector>

namespace leetcode {
namespace problem_2420 {

static std::vector<int> goodIndicesImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());

  // pre[i] = length of longest non-increasing segment ending at i
  std::vector<int> pre(n, 1);
  for (int i = 1; i < n; ++i) {
    if (nums[i] <= nums[i - 1]) {
      pre[i] = pre[i - 1] + 1;
    }
  }

  // suf[i] = length of longest non-decreasing segment starting at i
  std::vector<int> suf(n, 1);
  for (int i = n - 2; i >= 0; --i) {
    if (nums[i] <= nums[i + 1]) {
      suf[i] = suf[i + 1] + 1;
    }
  }

  std::vector<int> result;
  for (int i = k; i < n - k; ++i) {
    if (pre[i - 1] >= k && suf[i + 1] >= k) {
      result.push_back(i);
    }
  }
  return result;
}

FindAllGoodIndicesSolution::FindAllGoodIndicesSolution() {
  setMetaInfo({.id = 2420,
               .title = "Find All Good Indices",
               .url = "https://leetcode.com/problems/find-all-good-indices/"});
  registerStrategy(
      {.name = "Prefix Suffix Arrays",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Dynamic Programming", "Prefix Sum"}},
      goodIndicesImpl);
}

std::vector<int> FindAllGoodIndicesSolution::goodIndices(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2420
}  // namespace leetcode
