#ifndef LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_DIGIT_SUM_EQUAL_TO_INDEX_H__
#define LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_DIGIT_SUM_EQUAL_TO_INDEX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3550 {

using Func = std::function<int(std::vector<int>&)>;

class SmallestIndexWithDigitSumEqualToIndexSolution
    : public SolutionBase<Func> {
 public:
  SmallestIndexWithDigitSumEqualToIndexSolution();

  int smallestIndex(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3550

#endif  // LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_DIGIT_SUM_EQUAL_TO_INDEX_H__
