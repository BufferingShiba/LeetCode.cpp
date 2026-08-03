#include "leetcode/problems/string-matching-in-an-array.h"

namespace leetcode {
namespace problem_1408 {

namespace {

std::vector<std::string> stringMatchingImpl(std::vector<std::string>& words) {
  std::vector<std::string> result;
  const int n = static_cast<int>(words.size());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (words[j].find(words[i]) != std::string::npos) {
        result.push_back(words[i]);
        break;
      }
    }
  }
  return result;
}

}  // namespace

StringMatchingInAnArraySolution::StringMatchingInAnArraySolution() {
  setMetaInfo({.id = 1408,
               .title = "String Matching in an Array",
               .url = "https://leetcode.com/problems/string-matching-in-an-array/"});
  registerStrategy({.name = "bruteforce",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2 * L)",
                    .space_complexity = "O(n * L)",
                    .tags = {"Array", "String", "String Matching"}},
                   stringMatchingImpl);
}

std::vector<std::string> StringMatchingInAnArraySolution::stringMatching(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_1408
}  // namespace leetcode
