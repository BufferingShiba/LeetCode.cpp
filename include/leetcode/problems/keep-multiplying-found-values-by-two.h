#ifndef LEETCODE_PROBLEMS_KEEP_MULTIPLYING_FOUND_VALUES_BY_TWO_H__
#define LEETCODE_PROBLEMS_KEEP_MULTIPLYING_FOUND_VALUES_BY_TWO_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2154 {

using Func = std::function<int(std::vector<int>&, int)>;

class KeepMultiplyingFoundValuesByTwoSolution
    : public SolutionBase<Func> {
 public:
  KeepMultiplyingFoundValuesByTwoSolution();

  int findFinalValue(std::vector<int>& nums, int original);
};

}  // namespace problem_2154
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_KEEP_MULTIPLYING_FOUND_VALUES_BY_TWO_H__
