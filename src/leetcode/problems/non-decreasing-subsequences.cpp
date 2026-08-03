#include "leetcode/problems/non-decreasing-subsequences.h"

#include <set>

namespace leetcode::problem_491 {

namespace {

void Dfs(const std::vector<int>& nums, int index, std::vector<int>& path,
         std::vector<std::vector<int>>& result, std::set<std::vector<int>>& seen) {
  for (int i = index; i < static_cast<int>(nums.size()); ++i) {
    if (!path.empty() && nums[i] < path.back()) continue;
    path.push_back(nums[i]);
    if (path.size() >= 2 && seen.insert(path).second) {
      result.push_back(path);
    }
    Dfs(nums, i + 1, path, result, seen);
    path.pop_back();
  }
}

std::vector<std::vector<int>> findSubsequencesImpl(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> path;
  std::set<std::vector<int>> seen;
  Dfs(nums, 0, path, result, seen);
  return result;
}

}  // namespace

NonDecreasingSubsequencesSolution::NonDecreasingSubsequencesSolution() {
  setMetaInfo({.id = 491,
               .title = "Non-decreasing Subsequences",
               .url = "https://leetcode.com/problems/non-decreasing-subsequences/"});
  registerStrategy({.name = "BacktrackingWithSetDedup",
                    .expected = "Accepted",
                    .time_complexity = "O(2^n)",
                    .space_complexity = "O(2^n)",
                    .tags = {"Backtracking", "Set", "Array"}},
                   findSubsequencesImpl);
}

std::vector<std::vector<int>>
NonDecreasingSubsequencesSolution::findSubsequences(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_491
