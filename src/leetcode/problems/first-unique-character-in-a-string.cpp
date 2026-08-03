#include "leetcode/problems/first-unique-character-in-a-string.h"

namespace leetcode {
namespace problem_387 {
namespace {

int firstUniqCharImpl(std::string s) {
  int count[26] = {0};
  for (char c : s) {
    ++count[c - 'a'];
  }
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (count[s[i] - 'a'] == 1) {
      return i;
    }
  }
  return -1;
}

}  // namespace

FirstUniqueCharacterInAStringSolution::FirstUniqueCharacterInAStringSolution() {
  setMetaInfo({.id = 387,
               .title = "First Unique Character in a String",
               .url = "https://leetcode.com/problems/first-unique-character-in-a-string/"});
  registerStrategy({.name = "counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Queue", "Counting"}},
                   firstUniqCharImpl);
}

int FirstUniqueCharacterInAStringSolution::firstUniqChar(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_387
}  // namespace leetcode
