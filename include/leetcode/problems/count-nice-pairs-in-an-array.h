#ifndef LEETCODE_PROBLEMS_COUNT_NICE_PAIRS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_COUNT_NICE_PAIRS_IN_AN_ARRAY_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_1814 {

using Func = std::function<int(std::vector<int>&)>;

class CountNicePairsInAnArraySolution
    : public SolutionBase<Func> {
 public:
  CountNicePairsInAnArraySolution();

  int countNicePairs(std::vector<int>& nums);
};

}  // namespace problem_1814
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NICE_PAIRS_IN_AN_ARRAY_H__
