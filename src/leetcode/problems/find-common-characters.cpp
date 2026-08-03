#include "leetcode/problems/find-common-characters.h"

#include <algorithm>
#include <array>
#include <limits>

namespace leetcode {
namespace problem_1002 {

namespace {

std::vector<std::string> commonCharsImpl(std::vector<std::string>& words) {
  std::array<int, 26> common;
  common.fill(std::numeric_limits<int>::max());

  for (const auto& word : words) {
    std::array<int, 26> count{};
    for (char c : word) {
      ++count[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      common[i] = std::min(common[i], count[i]);
    }
  }

  std::vector<std::string> result;
  for (int i = 0; i < 26; ++i) {
    std::string ch(1, static_cast<char>('a' + i));
    for (int j = 0; j < common[i]; ++j) {
      result.push_back(ch);
    }
  }
  return result;
}

}  // namespace

FindCommonCharactersSolution::FindCommonCharactersSolution() {
  setMetaInfo({.id = 1002,
               .title = "Find Common Characters",
               .url = "https://leetcode.com/problems/find-common-characters/"});
  registerStrategy(
      {.name = "MinFrequencyIntersection",
       .expected = "Accepted",
       .time_complexity = "O(n * L)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      commonCharsImpl);
}

std::vector<std::string> FindCommonCharactersSolution::commonChars(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_1002
}  // namespace leetcode
