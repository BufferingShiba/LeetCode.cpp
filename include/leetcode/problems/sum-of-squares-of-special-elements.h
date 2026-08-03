#ifndef LEETCODE_PROBLEMS_SUM_OF_SQUARES_OF_SPECIAL_ELEMENTS_H__
#define LEETCODE_PROBLEMS_SUM_OF_SQUARES_OF_SPECIAL_ELEMENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2778 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfSquaresOfSpecialElementsSolution
    : public SolutionBase<Func> {
 public:
  SumOfSquaresOfSpecialElementsSolution();

  int sumOfSquares(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2778

#endif  // LEETCODE_PROBLEMS_SUM_OF_SQUARES_OF_SPECIAL_ELEMENTS_H__
