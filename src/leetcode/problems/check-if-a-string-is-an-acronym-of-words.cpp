#include "leetcode/problems/check-if-a-string-is-an-acronym-of-words.h"

namespace leetcode {
namespace problem_2828 {

namespace {

bool isAcronymImpl(std::vector<std::string>& words, std::string s) {
  if (words.size() != s.size()) {
    return false;
  }
  for (size_t i = 0; i < words.size(); ++i) {
    if (words[i].empty() || words[i][0] != s[i]) {
      return false;
    }
  }
  return true;
}

}  // namespace

bool CheckIfAStringIsAnAcronymOfWordsSolution::isAcronym(
    std::vector<std::string>& words, std::string s) {
  return getSolution()(words, std::move(s));
}

CheckIfAStringIsAnAcronymOfWordsSolution::CheckIfAStringIsAnAcronymOfWordsSolution() {
  setMetaInfo({.id = 2828,
               .title = "Check if a String Is an Acronym of Words",
               .url = "https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/"});
  registerStrategy({.name = "greedy-single-pass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "String"}},
                   isAcronymImpl);
}

}  // namespace problem_2828
}  // namespace leetcode
