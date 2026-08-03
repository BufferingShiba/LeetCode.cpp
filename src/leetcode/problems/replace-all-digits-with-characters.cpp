#include "leetcode/problems/replace-all-digits-with-characters.h"

namespace leetcode {
namespace problem_1844 {
namespace {

std::string replaceDigitsImpl(std::string s) {
  for (std::size_t i = 1; i < s.size(); i += 2) {
    s[i] = static_cast<char>(s[i - 1] + (s[i] - '0'));
  }
  return s;
}

}  // namespace

ReplaceAllDigitsWithCharactersSolution::ReplaceAllDigitsWithCharactersSolution() {
  setMetaInfo({.id = 1844,
               .title = "Replace All Digits with Characters",
               .url = "https://leetcode.com/problems/replace-all-digits-with-characters/"});

  registerStrategy(
      {.name = "single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      replaceDigitsImpl);
}

std::string ReplaceAllDigitsWithCharactersSolution::replaceDigits(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1844
}  // namespace leetcode
