#ifndef LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_II_H__
#define LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_II_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3251 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheCountOfMonotonicPairsIiSolution
    : public SolutionBase<Func> {
 public:
  FindTheCountOfMonotonicPairsIiSolution();
  int countOfPairs(std::vector<int>& nums);
};

}  // namespace problem_3251
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_COUNT_OF_MONOTONIC_PAIRS_II_H__
