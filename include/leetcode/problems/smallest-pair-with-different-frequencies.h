#ifndef LEETCODE_PROBLEMS_SMALLEST_PAIR_WITH_DIFFERENT_FREQUENCIES_H__
#define LEETCODE_PROBLEMS_SMALLEST_PAIR_WITH_DIFFERENT_FREQUENCIES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3852 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SmallestPairWithDifferentFrequenciesSolution
    : public SolutionBase<Func> {
 public:
  std::vector<int> minDistinctFreqPair(std::vector<int>& nums);

  SmallestPairWithDifferentFrequenciesSolution();
};

}  // namespace leetcode::problem_3852

#endif  // LEETCODE_PROBLEMS_SMALLEST_PAIR_WITH_DIFFERENT_FREQUENCIES_H__
