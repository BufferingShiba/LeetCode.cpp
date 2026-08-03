#include "leetcode/problems/number-of-strings-that-appear-as-substrings-in-word.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1967 {
namespace {

int numOfStringsImpl(std::vector<std::string>& patterns, std::string word) {
  int count = 0;
  for (const auto& p : patterns) {
    if (word.find(p) != std::string::npos) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfStringsThatAppearAsSubstringsInWordSolution::
    NumberOfStringsThatAppearAsSubstringsInWordSolution() {
  setMetaInfo(
      {.id = 1967,
       .title = "Number of Strings That Appear as Substrings in Word",
       .url = "https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/"});
  registerStrategy(
      {.name = "linear_scan",
       .expected = "Accepted",
       .time_complexity = "O(n * m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      numOfStringsImpl);
}

int NumberOfStringsThatAppearAsSubstringsInWordSolution::numOfStrings(
    std::vector<std::string>& patterns, std::string word) {
  return getSolution()(patterns, word);
}

}  // namespace problem_1967
}  // namespace leetcode
