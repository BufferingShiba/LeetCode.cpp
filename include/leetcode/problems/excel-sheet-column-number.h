#ifndef LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_NUMBER_H_
#define LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_NUMBER_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_171 {

using Func = std::function<int(std::string)>;

class ExcelSheetColumnNumberSolution : public SolutionBase<Func> {
 public:
  ExcelSheetColumnNumberSolution();

  int titleToNumber(const std::string& columnTitle);
};

}  // namespace problem_171
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EXCEL_SHEET_COLUMN_NUMBER_H_
