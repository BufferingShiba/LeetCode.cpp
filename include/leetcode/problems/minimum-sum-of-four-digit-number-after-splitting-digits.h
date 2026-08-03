#ifndef LEETCODE_PROBLEMS_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_H_
#define LEETCODE_PROBLEMS_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2160 {

using Func = std::function<int(int)>;

class MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution
    : public SolutionBase<Func> {
 public:
  // 题目原方法
  int minimumSum(int num);

  MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution();
};

}  // namespace problem_2160
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SUM_OF_FOUR_DIGIT_NUMBER_AFTER_SPLITTING_DIGITS_H_
