#ifndef LEETCODE_PROBLEMS_CALCULATE_DIGIT_SUM_OF_A_STRING_H_
#define LEETCODE_PROBLEMS_CALCULATE_DIGIT_SUM_OF_A_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2243 {

using Func = std::function<std::string(std::string, int)>;

class CalculateDigitSumOfAStringSolution : public SolutionBase<Func> {
 public:
  CalculateDigitSumOfAStringSolution();

  std::string digitSum(std::string s, int k) {
    return getSolution()(std::move(s), k);
  }
};

}  // namespace problem_2243
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CALCULATE_DIGIT_SUM_OF_A_STRING_H_
