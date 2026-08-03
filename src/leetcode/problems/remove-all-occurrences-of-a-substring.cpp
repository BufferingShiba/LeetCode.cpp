#include "leetcode/problems/remove-all-occurrences-of-a-substring.h"

namespace leetcode {
namespace problem_1910 {

static std::string removeOccurrencesImpl(std::string s, std::string part) {
  std::string result;
  for (char c : s) {
    result.push_back(c);
    if (result.size() >= part.size() &&
        result.substr(result.size() - part.size()) == part) {
      result.erase(result.size() - part.size());
    }
  }
  return result;
}

RemoveAllOccurrencesOfASubstringSolution::RemoveAllOccurrencesOfASubstringSolution() {
  setMetaInfo({.id = 1910,
               .title = "Remove All Occurrences of a Substring",
               .url = "https://leetcode.com/problems/remove-all-occurrences-of-a-substring/"});
  registerStrategy(
      {.name = "Stack",
       .expected = "Accepted",
       .time_complexity = "O(n * m)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack", "Simulation"}},
      removeOccurrencesImpl);
}

std::string RemoveAllOccurrencesOfASubstringSolution::removeOccurrences(
    std::string s, std::string part) {
  return getSolution()(s, part);
}

}  // namespace problem_1910
}  // namespace leetcode
