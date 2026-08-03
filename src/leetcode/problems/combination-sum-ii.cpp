#include "leetcode/problems/combination-sum-ii.h"

#include <algorithm>
#include <functional>

namespace leetcode::problem_40 {

namespace {

std::vector<std::vector<int>> combinationSum2Impl(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());

  std::vector<std::vector<int>> result;
  std::vector<int> current;

  std::function<void(int, int)> backtrack = [&](int start, int remain) {
    if (remain == 0) {
      result.push_back(current);
      return;
    }

    for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
      // Skip duplicates at the same recursion depth
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }

      // Prune: since sorted, if current exceeds remain, further elements will too
      if (candidates[i] > remain) {
        break;
      }

      current.push_back(candidates[i]);
      backtrack(i + 1, remain - candidates[i]);
      current.pop_back();
    }
  };

  backtrack(0, target);
  return result;
}

}  // namespace

CombinationSumIiSolution::CombinationSumIiSolution() {
  setMetaInfo({.id = 40, .title = "Combination Sum II",
               .url = "https://leetcode.com/problems/combination-sum-ii/"});
  registerStrategy(
      {.name = "Backtracking with sorting",
       .expected = "Accepted",
       .time_complexity = "O(2^n) worst-case, heavily pruned",
       .space_complexity = "O(n) recursion stack",
       .tags = {"Array", "Backtracking"}},
      combinationSum2Impl);
}

}  // namespace leetcode::problem_40
