#ifndef LEETCODE_PROBLEMS_NUMBER_OF_GOOD_PAIRS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_GOOD_PAIRS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1512 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfGoodPairsSolution : public SolutionBase<Func> {
 public:
  NumberOfGoodPairsSolution();

  int numIdenticalPairs(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1512

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_GOOD_PAIRS_H__
