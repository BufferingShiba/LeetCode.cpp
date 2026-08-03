#include "leetcode/problems/find-all-k-distant-indices-in-an-array.h"

namespace leetcode::problem_2200 {

namespace {

std::vector<int> findKDistantIndicesImpl(std::vector<int>& nums, int key, int k) {
  int n = static_cast<int>(nums.size());
  std::vector<int> result;
  int last = -1;
  for (int j = 0; j < n; ++j) {
    if (nums[j] != key) {
      continue;
    }
    int lo = std::max(0, j - k);
    int hi = std::min(n - 1, j + k);
    for (int i = std::max(lo, last + 1); i <= hi; ++i) {
      result.push_back(i);
    }
    last = hi;
  }
  return result;
}

}  // namespace

std::vector<int> FindAllKDistantIndicesInAnArraySolution::findKDistantIndices(
    std::vector<int>& nums, int key, int k) {
  return getSolution()(nums, key, k);
}

FindAllKDistantIndicesInAnArraySolution::FindAllKDistantIndicesInAnArraySolution()
    : SolutionBase<Func>() {
  setMetaInfo({.id = 2200,
               .title = "Find All K-Distant Indices in an Array",
               .url = "https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/"});
  registerStrategy({.name = "SweepIntervals",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   &findKDistantIndicesImpl);
}

}  // namespace leetcode::problem_2200
