#ifndef LEETCODE_PROBLEMS_CLEAR_DIGITS_H_
#define LEETCODE_PROBLEMS_CLEAR_DIGITS_H_

#include "leetcode/core.h"

namespace leetcode::problem_3174 {

using Func = std::function<std::string(std::string)>;

class ClearDigitsSolution : public SolutionBase<Func> {
 public:
  ClearDigitsSolution();

  std::string clearDigits(std::string s);
};

}  // namespace leetcode::problem_3174

#endif  // LEETCODE_PROBLEMS_CLEAR_DIGITS_H_
