#include "leetcode/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n.h"

namespace leetcode::problem_1415 {

// 回溯按字典序枚举所有 happy 字符串直到找到第 k 个。字符顺序 a -> b -> c。
static std::string getHappyStringImpl(int n, int k) {
  std::string result;
  int count = 0;
  std::string current;

  std::function<void(int)> dfs = [&](int pos) {
    if (!result.empty()) return;  // 已找到
    if (pos == n) {
      ++count;
      if (count == k) result = current;
      return;
    }
    for (char c = 'a'; c <= 'c'; ++c) {
      if (!current.empty() && current.back() == c) continue;  // 相邻不同
      current.push_back(c);
      dfs(pos + 1);
      current.pop_back();
    }
  };

  dfs(0);
  return result;
}

TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution::
    TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution() {
  setMetaInfo({.id = 1415,
               .title = "The k-th Lexicographical String of All Happy Strings of Length n",
               .url = "https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(k * n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Backtracking"}},
      getHappyStringImpl);
}

std::string TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution::getHappyString(
    int n, int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_1415
