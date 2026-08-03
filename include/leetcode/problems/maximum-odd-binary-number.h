#ifndef LEETCODE_PROBLEMS_MAXIMUM_ODD_BINARY_NUMBER_H__
#define LEETCODE_PROBLEMS_MAXIMUM_ODD_BINARY_NUMBER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2864 {

using MaximumOddBinaryNumberFunc = std::function<std::string(std::string)>;

class MaximumOddBinaryNumberSolution
    : public SolutionBase<MaximumOddBinaryNumberFunc> {
 public:
  MaximumOddBinaryNumberSolution();

  std::string maximumOddBinaryNumber(std::string s);
};

}  // namespace leetcode::problem_2864

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ODD_BINARY_NUMBER_H__
