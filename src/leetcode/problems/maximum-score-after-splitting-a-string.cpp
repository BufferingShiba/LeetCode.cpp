#include "leetcode/problems/maximum-score-after-splitting-a-string.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_1422 {

namespace {

// 单次遍历：先统计总 '1' 数，再遍历分割点维护 leftZeros 和 leftOnes。
// 对每个分割点 i（1 <= i < n），left = s[0..i-1]，right = s[i..n-1]。
// 分数 = leftZeros + (totalOnes - leftOnes)。
int maxScoreImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  int totalOnes = 0;
  for (char c : s) {
    if (c == '1') {
      ++totalOnes;
    }
  }

  int leftZeros = 0;
  int leftOnes = 0;
  int best = 0;
  // 分割点从 1 到 n-1，保证左右都非空。
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '0') {
      ++leftZeros;
    } else {
      ++leftOnes;
    }
    best = std::max(best, leftZeros + (totalOnes - leftOnes));
  }
  return best;
}

}  // namespace

MaximumScoreAfterSplittingAString::MaximumScoreAfterSplittingAString() {
  setMetaInfo({.id = 1422,
               .title = "Maximum Score After Splitting a String",
               .url =
                   "https://leetcode.com/problems/maximum-score-after-splitting-a-string/"});
  registerStrategy(
      {.name = "single_pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Prefix Sum"}},
      maxScoreImpl);
}

int MaximumScoreAfterSplittingAString::maxScore(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1422
}  // namespace leetcode
