#include "leetcode/problems/words-within-two-edits-of-dictionary.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2452 {

namespace {

// 对每个 query 与 dictionary 中每个词逐字符比较（Hamming 距离），
// 若不同字符数不超过 2 则匹配。复杂度 O(Q*D*n)。
std::vector<std::string> twoEditWordsImpl(
    std::vector<std::string>& queries,
    std::vector<std::string>& dictionary) {
  std::vector<std::string> result;
  for (const std::string& q : queries) {
    bool matched = false;
    for (const std::string& d : dictionary) {
      int diff = 0;
      for (int i = 0; i < static_cast<int>(q.size()); ++i) {
        if (q[i] != d[i]) ++diff;
      }
      if (diff <= 2) {
        matched = true;
        break;
      }
    }
    if (matched) result.push_back(q);
  }
  return result;
}

}  // namespace

WordsWithinTwoEditsOfDictionarySolution::WordsWithinTwoEditsOfDictionarySolution() {
  setMetaInfo({
      .id = 2452,
      .title = "Words Within Two Edits of Dictionary",
      .url = "https://leetcode.com/problems/words-within-two-edits-of-dictionary/",
  });
  registerStrategy(
      {
          .name = "bruteforce",
          .expected = "Accepted",
          .time_complexity = "O(Q*D*n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "String"},
      },
      twoEditWordsImpl);
}

std::vector<std::string> WordsWithinTwoEditsOfDictionarySolution::twoEditWords(
    std::vector<std::string>& queries,
    std::vector<std::string>& dictionary) {
  return getSolution()(queries, dictionary);
}

}  // namespace problem_2452
}  // namespace leetcode
