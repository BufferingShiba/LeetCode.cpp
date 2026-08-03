#ifndef LEETCODE_PROBLEMS_SUBTRACT_THE_PRODUCT_AND_SUM_OF_DIGITS_OF_AN_INTEGER_H__
#define LEETCODE_PROBLEMS_SUBTRACT_THE_PRODUCT_AND_SUM_OF_DIGITS_OF_AN_INTEGER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1281 {

using Func = std::function<int(int)>;

class SubtractTheProductAndSumOfDigitsOfAnIntegerSolution
    : public SolutionBase<Func> {
 public:
  SubtractTheProductAndSumOfDigitsOfAnIntegerSolution();

  int subtractProductAndSum(int n);
};

}  // namespace problem_1281
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBTRACT_THE_PRODUCT_AND_SUM_OF_DIGITS_OF_AN_INTEGER_H__
