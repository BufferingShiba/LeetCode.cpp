#include "leetcode/problems/excel-sheet-column-title.h"

namespace leetcode {
namespace problem_168 {

std::string ExcelSheetColumnTitleSolution::convertToTitleImpl(int columnNumber) {
  std::string result;
  int n = columnNumber;
  while (n > 0) {
    n -= 1;
    result.push_back(static_cast<char>('A' + (n % 26)));
    n /= 26;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace problem_168
}  // namespace leetcode
