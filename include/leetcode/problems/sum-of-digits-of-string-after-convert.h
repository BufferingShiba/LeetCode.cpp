#ifndef LEETCODE_PROBLEMS_SUM_OF_DIGITS_OF_STRING_AFTER_CONVERT_H__
#define LEETCODE_PROBLEMS_SUM_OF_DIGITS_OF_STRING_AFTER_CONVERT_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1945 {

using Func = std::function<int(std::string, int)>;

class SumOfDigitsOfStringAfterConvertSolution
    : public SolutionBase<Func> {
 public:
  SumOfDigitsOfStringAfterConvertSolution();

  int getLucky(std::string s, int k);
};

}  // namespace leetcode::problem_1945

#endif  // LEETCODE_PROBLEMS_SUM_OF_DIGITS_OF_STRING_AFTER_CONVERT_H__
