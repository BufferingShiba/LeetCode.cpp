#include "leetcode/problems/count-substrings-starting-and-ending-with-given-character.h"

namespace {

long long countSubstringsImpl(std::string s, char c) {
  long long k = 0;
  for (char ch : s) {
    if (ch == c) {
      ++k;
    }
  }
  return k * (k + 1) / 2;
}

}  // namespace

namespace leetcode {
namespace problem_3084 {

CountSubstringsStartingAndEndingWithGivenCharacterSolution::CountSubstringsStartingAndEndingWithGivenCharacterSolution() {
  setMetaInfo({.id = 3084, .title = "Count Substrings Starting and Ending with Given Character", .url = "https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/"});
  registerStrategy({.name = "CountOccurrences", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Math", "String", "Counting"}}, countSubstringsImpl);
}

long long CountSubstringsStartingAndEndingWithGivenCharacterSolution::countSubstrings(std::string s, char c) {
  return getSolution()(s, c);
}

}  // namespace problem_3084
}  // namespace leetcode
