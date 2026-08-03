#include "leetcode/problems/number-of-good-ways-to-split-a-string.h"

#include <array>
#include <string>

namespace leetcode::problem_1525 {

namespace {

int numSplitsImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  if (n < 2) return 0;

  std::array<int, 26> freq{};
  int right_distinct = 0;
  for (char ch : s) {
    int idx = ch - 'a';
    if (freq[idx] == 0) ++right_distinct;
    ++freq[idx];
  }

  std::array<bool, 26> in_left{};
  int left_distinct = 0;
  int result = 0;

  // 分割点在 i 和 i+1 之间，i 从 0 到 n-2
  for (int i = 0; i < n - 1; ++i) {
    int idx = s[i] - 'a';

    // 更新左侧
    if (!in_left[idx]) {
      in_left[idx] = true;
      ++left_distinct;
    }

    // 更新右侧
    --freq[idx];
    if (freq[idx] == 0) {
      --right_distinct;
    }

    if (left_distinct == right_distinct) {
      ++result;
    }
  }

  return result;
}

}  // namespace

NumberOfGoodWaysToSplitAStringSolution::NumberOfGoodWaysToSplitAStringSolution() {
  setMetaInfo({.id = 1525,
               .title = "Number of Good Ways to Split a String",
               .url = "https://leetcode.com/problems/number-of-good-ways-to-split-a-string/"});

  registerStrategy(
      {.name = "prefix-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Prefix Sum"}},
      numSplitsImpl);
}

int NumberOfGoodWaysToSplitAStringSolution::numSplits(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1525
