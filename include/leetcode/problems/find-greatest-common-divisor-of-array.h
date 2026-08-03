#ifndef LEETCODE_PROBLEMS_FIND_GREATEST_COMMON_DIVISOR_OF_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_GREATEST_COMMON_DIVISOR_OF_ARRAY_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1979 {

using Func = std::function<int(std::vector<int>&)>;

class FindGreatestCommonDivisorOfArraySolution
    : public SolutionBase<Func> {
 public:
  FindGreatestCommonDivisorOfArraySolution();

  int findGCD(std::vector<int>& nums);
};

}  // namespace problem_1979
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_GREATEST_COMMON_DIVISOR_OF_ARRAY_H_
