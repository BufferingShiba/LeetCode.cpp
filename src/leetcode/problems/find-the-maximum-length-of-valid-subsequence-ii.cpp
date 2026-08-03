#include "leetcode/problems/find-the-maximum-length-of-valid-subsequence-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3202 {

namespace {

// 交替余数对 DP。
// 关键观察：相邻和恒定 => 相隔一个位置的元素模 k 同余 => 余数序列在固定一对余数之间交替。
// len[a][b] = 交替对 {a,b} 下、以余数 b 结尾的最长有效子序列长度。
int maximumLengthImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  if (n <= 1) {
    return n;
  }

  std::vector<std::vector<int>> len(k, std::vector<int>(k, 0));
  int ans = 0;
  for (int v : nums) {
    const int r = v % k;
    // 以临时数组收集本轮对行 r 的更新，保证读取到的都是旧值。
    std::vector<int> row(k, 0);
    for (int p = 0; p < k; ++p) {
      const int base = (p == r) ? len[r][r] : len[p][r];  // 旧值
      int cand = 1;                                      // 单元素 r，伙伴 p
      if (base > 0) {
        cand = base + 1;  // 将 r 接到以 r 为前一个的 p 之后
      }
      row[p] = std::max(len[r][p], cand);
    }
    for (int p = 0; p < k; ++p) {
      len[r][p] = row[p];
      ans = std::max(ans, row[p]);
    }
  }
  return ans;
}

}  // namespace

FindTheMaximumLengthOfValidSubsequenceIiSolution::
    FindTheMaximumLengthOfValidSubsequenceIiSolution() {
  this->setMetaInfo({
      3202,
      "Find the Maximum Length of Valid Subsequence II",
      "https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/",
  });
  this->registerStrategy(
      {
          .name = "alternate-pair-dp",
          .expected = "Accepted",
          .time_complexity = "O(n * k)",
          .space_complexity = "O(k * k)",
          .tags = {"Array", "Dynamic Programming"},
      },
      maximumLengthImpl);
}

int FindTheMaximumLengthOfValidSubsequenceIiSolution::maximumLength(
    std::vector<int>& nums, int k) {
  return this->getSolution()(nums, k);
}

}  // namespace leetcode::problem_3202
