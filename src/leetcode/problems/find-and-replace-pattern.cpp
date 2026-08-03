#include "leetcode/problems/find-and-replace-pattern.h"

namespace leetcode {
namespace problem_890 {

static std::vector<std::string> findAndReplacePatternImpl(
    std::vector<std::string>& words, std::string pattern) {
  std::vector<std::string> result;
  for (const auto& word : words) {
    char p2w[26] = {0};
    char w2p[26] = {0};
    bool match = true;
    for (size_t i = 0; i < pattern.size(); ++i) {
      int pi = pattern[i] - 'a';
      int wi = word[i] - 'a';
      if (p2w[pi] == 0 && w2p[wi] == 0) {
        p2w[pi] = word[i];
        w2p[wi] = pattern[i];
      } else if (p2w[pi] != word[i] || w2p[wi] != pattern[i]) {
        match = false;
        break;
      }
    }
    if (match) {
      result.push_back(word);
    }
  }
  return result;
}

FindAndReplacePatternSolution::FindAndReplacePatternSolution() {
  setMetaInfo({.id = 890,
               .title = "Find and Replace Pattern",
               .url = "https://leetcode.com/problems/find-and-replace-pattern/"});
  registerStrategy(
      {.name = "BidirectionalMapping",
       .expected = "Accepted",
       .time_complexity = "O(N * L)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      findAndReplacePatternImpl);
}

std::vector<std::string> FindAndReplacePatternSolution::findAndReplacePattern(
    std::vector<std::string>& words, std::string pattern) {
  return getSolution()(words, pattern);
}

}  // namespace problem_890
}  // namespace leetcode
