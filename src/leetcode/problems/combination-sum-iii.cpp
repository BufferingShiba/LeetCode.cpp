#include "leetcode/problems/combination-sum-iii.h"

namespace {

void backtrack(int start, int k, int n, std::vector<int>& current,
               std::vector<std::vector<int>>& result) {
  if (k == 0) {
    if (n == 0) {
      result.push_back(current);
    }
    return;
  }

  // 剩余可选数字不足以凑齐 k 个
  if (start > 9 || 10 - start < k) {
    return;
  }

  // 最小可能和：start + (start+1) + ... + (start+k-1)
  int minSum = (start + start + k - 1) * k / 2;
  if (minSum > n) {
    return;
  }

  // 最大可能和：(9-k+1) + ... + 9
  int maxSum = (9 - k + 1 + 9) * k / 2;
  if (maxSum < n) {
    return;
  }

  for (int i = start; i <= 9; ++i) {
    if (i > n) {
      break;  // 当前数字已超过目标和，后面更大更不可能
    }
    current.push_back(i);
    backtrack(i + 1, k - 1, n - i, current, result);
    current.pop_back();
  }
}

std::vector<std::vector<int>> combinationSum3Impl(int k, int n) {
  std::vector<std::vector<int>> result;
  std::vector<int> current;
  backtrack(1, k, n, current, result);
  return result;
}

}  // namespace

namespace leetcode::problem_216 {

CombinationSumIiiSolution::CombinationSumIiiSolution() {
  setMetaInfo({.id = 216,
               .title = "Combination Sum III",
               .url = "https://leetcode.com/problems/combination-sum-iii/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(C(9,k))",
       .space_complexity = "O(k)",
       .tags = {"Array", "Backtracking"}},
      combinationSum3Impl);
}

std::vector<std::vector<int>> CombinationSumIiiSolution::combinationSum3(int k,
                                                                          int n) {
  return getSolution()(k, n);
}

}  // namespace leetcode::problem_216
