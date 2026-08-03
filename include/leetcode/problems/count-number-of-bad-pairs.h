#ifndef LEETCODE_PROBLEMS_COUNT_NUMBER_OF_BAD_PAIRS_H_
#define LEETCODE_PROBLEMS_COUNT_NUMBER_OF_BAD_PAIRS_H_

#include "leetcode/core.h"

namespace leetcode::problem_2364 {

using Func = std::function<long long(std::vector<int>&)>;

class CountNumberOfBadPairsSolution : public SolutionBase<Func> {
 public:
  CountNumberOfBadPairsSolution();

  long long countBadPairs(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2364

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBER_OF_BAD_PAIRS_H_
