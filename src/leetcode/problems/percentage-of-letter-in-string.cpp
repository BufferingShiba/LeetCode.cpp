#include "leetcode/problems/percentage-of-letter-in-string.h"

#include <string>

namespace leetcode {
namespace problem_2278 {

namespace {

int percentageLetterImpl(std::string s, char letter) {
  int count = 0;
  for (char c : s) {
    if (c == letter) {
      ++count;
    }
  }
  return count * 100 / static_cast<int>(s.size());
}

}  // namespace

PercentageOfLetterInStringSolution::PercentageOfLetterInStringSolution() {
  setMetaInfo({.id = 2278,
               .title = "Percentage of Letter in String",
               .url = "https://leetcode.com/problems/percentage-of-letter-in-string/"});
  registerStrategy({.name = "counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   static_cast<Func>(percentageLetterImpl));
}

int PercentageOfLetterInStringSolution::percentageLetter(std::string s,
                                                         char letter) {
  return getSolution()(std::move(s), letter);
}

}  // namespace problem_2278
}  // namespace leetcode
