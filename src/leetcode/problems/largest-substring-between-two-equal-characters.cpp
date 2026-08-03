#include "leetcode/problems/largest-substring-between-two-equal-characters.h"

namespace leetcode::problem_1624 {

namespace {

int maxLengthBetweenEqualCharactersImpl(std::string s) {
  int first[26];
  for (int i = 0; i < 26; ++i) {
    first[i] = -1;
  }
  int result = -1;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    int idx = s[i] - 'a';
    if (first[idx] == -1) {
      first[idx] = i;
    } else {
      result = std::max(result, i - first[idx] - 1);
    }
  }
  return result;
}

}  // namespace

LargestSubstringBetweenTwoEqualCharactersSolution::
    LargestSubstringBetweenTwoEqualCharactersSolution() {
  setMetaInfo({.id = 1624,
               .title = "Largest Substring Between Two Equal Characters",
               .url = "https://leetcode.com/problems/largest-substring-between-two-equal-characters/"});

  registerStrategy(
      {"hash-map-first-occurrence", "Accepted", "O(n)", "O(1)",
       {"Hash Table", "String"}},
      maxLengthBetweenEqualCharactersImpl);
}

int LargestSubstringBetweenTwoEqualCharactersSolution::
    maxLengthBetweenEqualCharacters(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1624
