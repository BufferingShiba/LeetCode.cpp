#ifndef LEETCODE_PROBLEMS_SUM_OF_GOOD_NUMBERS_H__
#define LEETCODE_PROBLEMS_SUM_OF_GOOD_NUMBERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3452 {

using Func = std::function<int(std::vector<int>&, int)>;

class SumOfGoodNumbersSolution : public SolutionBase<Func> {
 public:
  SumOfGoodNumbersSolution();

  int sumOfGoodNumbers(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3452

#endif  // LEETCODE_PROBLEMS_SUM_OF_GOOD_NUMBERS_H__
