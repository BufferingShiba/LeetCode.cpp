#ifndef LEETCODE_PROBLEMS_3883_COUNT_NON_DECREASING_ARRAYS_WITH_GIVEN_DIGIT_SUMS_H_
#define LEETCODE_PROBLEMS_3883_COUNT_NON_DECREASING_ARRAYS_WITH_GIVEN_DIGIT_SUMS_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3883 {

using Func = std::function<int(std::vector<int>&)>;

class CountNonDecreasingArraysWithGivenDigitSumsSolution
    : public SolutionBase<Func> {
 public:
  CountNonDecreasingArraysWithGivenDigitSumsSolution();

  int countArrays(std::vector<int>& digitSum) {
    return getSolution()(digitSum);
  }
};

}  // namespace problem_3883
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_3883_COUNT_NON_DECREASING_ARRAYS_WITH_GIVEN_DIGIT_SUMS_H_
