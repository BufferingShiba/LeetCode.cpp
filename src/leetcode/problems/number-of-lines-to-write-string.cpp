#include "leetcode/problems/number-of-lines-to-write-string.h"

namespace leetcode::problem_806 {

namespace {

std::vector<int> numberOfLinesImpl(std::vector<int>& widths, std::string s) {
  constexpr int kMaxWidth = 100;
  int lines = 1;
  int curWidth = 0;

  for (char c : s) {
    int w = widths[c - 'a'];
    if (curWidth + w > kMaxWidth) {
      ++lines;
      curWidth = w;
    } else {
      curWidth += w;
    }
  }

  return {lines, curWidth};
}

}  // namespace

NumberOfLinesToWriteStringSolution::NumberOfLinesToWriteStringSolution() {
  setMetaInfo({.id = 806,
               .title = "Number of Lines To Write String",
               .url = "https://leetcode.com/problems/number-of-lines-to-write-string/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      numberOfLinesImpl);
}

std::vector<int> NumberOfLinesToWriteStringSolution::numberOfLines(
    std::vector<int>& widths, std::string s) {
  return getSolution()(widths, s);
}

}  // namespace leetcode::problem_806
