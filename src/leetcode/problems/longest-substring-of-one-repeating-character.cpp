#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/longest-substring-of-one-repeating-character.h"

namespace leetcode {
namespace problem_2213 {
namespace {

/**
 * 迭代式线段树。叶子节点存 (left_char, right_char, prefix, suffix, best, len)。
 * 合并：若左节点 right_char == 右节点 left_char，则可跨区间拼接。
 */
std::vector<int> longestRepeatingImpl(std::string s, std::string queryCharacters,
                                      std::vector<int>& queryIndices) {
  const int n = static_cast<int>(s.size());
  int size = 1;
  while (size < n) size <<= 1;

  const int M = 2 * size;
  std::vector<char> lchar(M, 0), rchar(M, 0);
  std::vector<int> pref(M, 0), suf(M, 0), best(M, 0), len(M, 0);

  auto set_leaf = [&](int idx, char c) {
    lchar[idx] = c;
    rchar[idx] = c;
    pref[idx] = 1;
    suf[idx] = 1;
    best[idx] = 1;
    len[idx] = 1;
  };

  for (int i = 0; i < n; ++i) {
    set_leaf(size + i, s[i]);
  }
  // 超出 n 的叶子为空的 sentinel（len=0, best=0）

  auto pull = [&](int idx, int li, int ri) {
    if (len[li] == 0) {
      // 左子空，直接取右子
      lchar[idx] = lchar[ri];
      rchar[idx] = rchar[ri];
      pref[idx] = pref[ri];
      suf[idx] = suf[ri];
      best[idx] = best[ri];
      len[idx] = len[ri];
      return;
    }
    if (len[ri] == 0) {
      lchar[idx] = lchar[li];
      rchar[idx] = rchar[li];
      pref[idx] = pref[li];
      suf[idx] = suf[li];
      best[idx] = best[li];
      len[idx] = len[li];
      return;
    }
    lchar[idx] = lchar[li];
    rchar[idx] = rchar[ri];
    len[idx] = len[li] + len[ri];
    pref[idx] = pref[li];
    suf[idx] = suf[ri];
    best[idx] = std::max(best[li], best[ri]);
    if (rchar[li] == lchar[ri]) {
      int cross = suf[li] + pref[ri];
      best[idx] = std::max(best[idx], cross);
      if (len[li] == pref[li]) {
        pref[idx] = len[li] + pref[ri];
      }
      if (len[ri] == suf[ri]) {
        suf[idx] = suf[li] + len[ri];
      }
    }
  };

  for (int i = size - 1; i >= 1; --i) {
    pull(i, i * 2, i * 2 + 1);
  }

  std::vector<int> result;
  result.reserve(queryIndices.size());

  for (int q = 0; q < static_cast<int>(queryIndices.size()); ++q) {
    int pos = queryIndices[q];
    char c = queryCharacters[q];
    int idx = size + pos;
    set_leaf(idx, c);
    idx /= 2;
    while (idx >= 1) {
      pull(idx, idx * 2, idx * 2 + 1);
      idx /= 2;
    }
    result.push_back(best[1]);
  }
  return result;
}

}  // namespace

LongestSubstringOfOneRepeatingCharacterSolution::
    LongestSubstringOfOneRepeatingCharacterSolution() {
  setMetaInfo({.id = 2213,
               .title = "Longest Substring of One Repeating Character",
               .url = "https://leetcode.com/problems/longest-substring-of-one-repeating-character/"});
  registerStrategy(
      {.name = "SegmentTree",
       .expected = "Accepted",
       .time_complexity = "O((n + k) * log n)",
       .space_complexity = "O(n)",
       .tags = {"Segment Tree"}},
      longestRepeatingImpl);
}

std::vector<int> LongestSubstringOfOneRepeatingCharacterSolution::longestRepeating(
    std::string s, std::string queryCharacters, std::vector<int>& queryIndices) {
  return getSolution()(std::move(s), std::move(queryCharacters), queryIndices);
}

}  // namespace problem_2213
}  // namespace leetcode
