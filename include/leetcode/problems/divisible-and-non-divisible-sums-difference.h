#ifndef LEETCODE_PROBLEMS_DIVISIBLE_AND_NON_DIVISIBLE_SUMS_DIFFERENCE_H_
#define LEETCODE_PROBLEMS_DIVISIBLE_AND_NON_DIVISIBLE_SUMS_DIFFERENCE_H_

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_2894 {

using Func = std::function<int(int n, int m)>;

class DivisibleAndNonDivisibleSumsDifferenceSolution
    : public SolutionBase<Func> {
 public:
  DivisibleAndNonDivisibleSumsDifferenceSolution();
  int differenceOfSums(int n, int m);
};

}  // namespace problem_2894
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIVISIBLE_AND_NON_DIVISIBLE_SUMS_DIFFERENCE_H_
