#include "leetcode/problems/count-asterisks.h"

namespace leetcode {
namespace problem_2315 {

namespace {

int countAsterisksImpl(std::string s) {
  int count = 0;
  bool inside = false;
  for (char ch : s) {
    if (ch == '|') {
      inside = !inside;
    } else if (ch == '*' && !inside) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountAsterisksSolution::CountAsterisksSolution() {
  setMetaInfo({.id = 2315,
                .title = "Count Asterisks",
                .url = "https://leetcode.com/problems/count-asterisks/"});
  registerStrategy(
      {.name = "SinglePass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      countAsterisksImpl);
  setDefaultStrategy();
}

int CountAsterisksSolution::countAsterisks(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2315
}  // namespace leetcode
