#ifndef LEETCODE_PROBLEMS_MAXIMIZE_SUM_OF_SQUARES_OF_DIGITS_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_SUM_OF_SQUARES_OF_DIGITS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_3723 {

using Func = std::function<std::string(int, int)>;

class MaximizeSumOfSquaresOfDigitsSolution : public SolutionBase<Func> {
 public:
  MaximizeSumOfSquaresOfDigitsSolution();
  std::string maxSumOfSquares(int num, int sum);
};

}  // namespace problem_3723
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_SUM_OF_SQUARES_OF_DIGITS_H__
