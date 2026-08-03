#ifndef LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_TITLE_H__
#define LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_TITLE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_168 {

using Func = std::function<std::string(int)>;

class ExcelSheetColumnTitleSolution : public SolutionBase<Func> {
 public:
  ExcelSheetColumnTitleSolution() {
    setMetaInfo({.id = 168,
                 .title = "Excel Sheet Column Title",
                 .url = "https://leetcode.com/problems/excel-sheet-column-title/"});

    registerStrategy(
        {.name = "iterative-base-26",
         .expected = "Accepted",
         .time_complexity = "O(log₍₂₆₎ n)",
         .space_complexity = "O(log₍₂₆₎ n)",
         .tags = {"Math", "String"}},
        convertToTitleImpl);
  }

  std::string convertToTitle(int columnNumber) {
    return getSolution()(columnNumber);
  }

 private:
  static std::string convertToTitleImpl(int columnNumber);
};

}  // namespace problem_168
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_TITLE_H__
