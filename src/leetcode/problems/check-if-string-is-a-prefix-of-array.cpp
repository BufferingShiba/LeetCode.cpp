#include "leetcode/problems/check-if-string-is-a-prefix-of-array.h"

namespace leetcode {
namespace problem_1961 {

static bool isPrefixStringImpl(std::string s,
                               std::vector<std::string>& words) {
  int pos = 0;
  for (const std::string& w : words) {
    if (pos + static_cast<int>(w.size()) > static_cast<int>(s.size()) ||
        s.compare(pos, w.size(), w) != 0) {
      return false;
    }
    pos += static_cast<int>(w.size());
    if (pos == static_cast<int>(s.size())) {
      return true;
    }
  }
  return false;
}

CheckIfStringIsAPrefixOfArraySolution::
    CheckIfStringIsAPrefixOfArraySolution() {
  setMetaInfo({.id = 1961,
               .title = "Check If String Is a Prefix of Array",
               .url = "https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/"});

  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "String"}},
      isPrefixStringImpl);
}

bool CheckIfStringIsAPrefixOfArraySolution::isPrefixString(
    std::string s, std::vector<std::string>& words) {
  return getSolution()(s, words);
}

}  // namespace problem_1961
}  // namespace leetcode
