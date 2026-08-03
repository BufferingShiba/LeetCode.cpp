#ifndef LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ELEMENT_SUM_AND_DIGIT_SUM_OF_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ELEMENT_SUM_AND_DIGIT_SUM_OF_AN_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2535 {

using Func = std::function<int(std::vector<int>&)>;

class DifferenceBetweenElementSumAndDigitSumOfAnArraySolution
    : public SolutionBase<Func> {
 public:
  DifferenceBetweenElementSumAndDigitSumOfAnArraySolution();

  int differenceOfSum(std::vector<int>& nums);
};

}  // namespace problem_2535
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ELEMENT_SUM_AND_DIGIT_SUM_OF_AN_ARRAY_H_
