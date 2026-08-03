#include "leetcode/problems/short-encoding-of-words.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_820 {

namespace {

int minimumLengthEncodingImpl(std::vector<std::string>& words) {
  std::unordered_set<std::string> wordSet(words.begin(), words.end());

  for (const auto& w : words) {
    // 检查每个真后缀（从第 1 个字符到末尾）
    for (size_t i = 1; i < w.size(); ++i) {
      std::string suffix = w.substr(i);
      wordSet.erase(suffix);
    }
  }

  int total = 0;
  for (const auto& w : wordSet) {
    total += static_cast<int>(w.size()) + 1;  // 单词长度 + '#'
  }
  return total;
}

}  // namespace

ShortEncodingOfWordsSolution::ShortEncodingOfWordsSolution() {
  setMetaInfo({.id = 820,
               .title = "Short Encoding of Words",
               .url = "https://leetcode.com/problems/short-encoding-of-words/"});

  registerStrategy(
      {.name = "HashSet suffix elimination",
       .expected = "Accepted",
       .time_complexity = "O(N * L^2)",
       .space_complexity = "O(N * L)",
       .tags = {"Array", "Hash Table", "String"}},
      minimumLengthEncodingImpl);
}

int ShortEncodingOfWordsSolution::minimumLengthEncoding(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_820
}  // namespace leetcode
