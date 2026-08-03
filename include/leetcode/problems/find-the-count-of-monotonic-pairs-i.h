#ifndef LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_I_H_
#define LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_I_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3250 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheCountOfMonotonicPairsISolution : public SolutionBase<Func> {
 public:
  FindTheCountOfMonotonicPairsISolution();

  int countOfPairs(std::vector<int>& nums);
};

}  // namespace problem_3250
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_I_H_
