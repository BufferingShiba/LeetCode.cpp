#include "leetcode/problems/expressive-words.h"

namespace leetcode {
namespace problem_809 {

static int expressiveWordsImpl(std::string s, std::vector<std::string>& words) {
  int count = 0;
  int n = static_cast<int>(s.size());

  for (const auto& w : words) {
    int i = 0, j = 0;
    int m = static_cast<int>(w.size());
    bool ok = true;

    while (i < n && j < m) {
      if (s[i] != w[j]) {
        ok = false;
        break;
      }
      char c = s[i];

      int cnt_s = 0;
      while (i < n && s[i] == c) {
        ++i;
        ++cnt_s;
      }

      int cnt_w = 0;
      while (j < m && w[j] == c) {
        ++j;
        ++cnt_w;
      }

      if (cnt_w > cnt_s) {
        ok = false;
        break;
      }
      if (cnt_w < cnt_s && cnt_s < 3) {
        ok = false;
        break;
      }
    }

    if (ok && i == n && j == m) {
      ++count;
    }
  }

  return count;
}

ExpressiveWordsSolution::ExpressiveWordsSolution() {
  setMetaInfo({.id = 809,
               .title = "Expressive Words",
               .url = "https://leetcode.com/problems/expressive-words/"});
  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(N * (|S| + |W|))",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "String"}},
      expressiveWordsImpl);
}

int ExpressiveWordsSolution::expressiveWords(std::string s,
                                              std::vector<std::string>& words) {
  return getSolution()(s, words);
}

}  // namespace problem_809
}  // namespace leetcode
