#ifndef LEETCODE_PROBLEMS_LARGEST_3_SAME_DIGIT_NUMBER_IN_STRING_H__
#define LEETCODE_PROBLEMS_LARGEST_3_SAME_DIGIT_NUMBER_IN_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2264 {

using Func = std::function<std::string(std::string)>;

class Largest3SameDigitNumberInStringSolution
    : public SolutionBase<Func> {
 public:
  Largest3SameDigitNumberInStringSolution();
  std::string largestGoodInteger(std::string num);
};

}  // namespace leetcode::problem_2264

#endif  // LEETCODE_PROBLEMS_LARGEST_3_SAME_DIGIT_NUMBER_IN_STRING_H__
