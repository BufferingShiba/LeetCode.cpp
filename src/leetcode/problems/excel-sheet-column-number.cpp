#include "leetcode/problems/excel-sheet-column-number.h"

namespace leetcode {
namespace problem_171 {

namespace {

// Scan the title left-to-right as a base-26 number (1-based letters).
int titleToNumberImpl(const std::string& columnTitle) {
  int result = 0;
  for (char c : columnTitle) {
    result = result * 26 + (c - 'A' + 1);
  }
  return result;
}

}  // namespace

ExcelSheetColumnNumberSolution::ExcelSheetColumnNumberSolution() {
  setMetaInfo({.id = 171,
               .title = "Excel Sheet Column Number",
               .url = "https://leetcode.com/problems/excel-sheet-column-number/"});
  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String"}},
      titleToNumberImpl);
}

int ExcelSheetColumnNumberSolution::titleToNumber(const std::string& columnTitle) {
  return getSolution()(columnTitle);
}

}  // namespace problem_171
}  // namespace leetcode
