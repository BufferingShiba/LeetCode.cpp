#include "leetcode/problems/removing-stars-from-a-string.h"

namespace leetcode::problem_2390 {

static std::string removeStarsImpl(std::string s) {
  std::string result;
  result.reserve(s.size());
  for (char c : s) {
    if (c == '*') {
      result.pop_back();
    } else {
      result.push_back(c);
    }
  }
  return result;
}

RemovingStarsFromAStringSolution::RemovingStarsFromAStringSolution() {
  setMetaInfo({.id = 2390,
               .title = "Removing Stars From a String",
               .url = "https://leetcode.com/problems/removing-stars-from-a-string/"});
  registerStrategy(
      {.name = "Stack Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack", "Simulation"}},
      removeStarsImpl);
}

std::string RemovingStarsFromAStringSolution::removeStars(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2390
