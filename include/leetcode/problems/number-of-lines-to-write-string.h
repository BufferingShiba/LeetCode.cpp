#ifndef LEETCODE_PROBLEMS_NUMBER_OF_LINES_TO_WRITE_STRING_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_LINES_TO_WRITE_STRING_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_806 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::string)>;

class NumberOfLinesToWriteStringSolution : public SolutionBase<Func> {
 public:
  NumberOfLinesToWriteStringSolution();

  std::vector<int> numberOfLines(std::vector<int>& widths, std::string s);
};

}  // namespace leetcode::problem_806

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_LINES_TO_WRITE_STRING_H_
