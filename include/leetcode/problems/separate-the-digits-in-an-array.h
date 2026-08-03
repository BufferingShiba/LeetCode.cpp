#ifndef LEETCODE_PROBLEMS_SEPARATE_THE_DIGITS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_SEPARATE_THE_DIGITS_IN_AN_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2553 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SeparateTheDigitsInAnArraySolution : public SolutionBase<Func> {
 public:
  SeparateTheDigitsInAnArraySolution();

  // 题目原方法
  std::vector<int> separateDigits(std::vector<int>& nums);
};

}  // namespace problem_2553
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SEPARATE_THE_DIGITS_IN_AN_ARRAY_H__
