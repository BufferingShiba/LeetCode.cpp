#ifndef LEETCODE_PROBLEMS_SUM_OF_MUTATED_ARRAY_CLOSEST_TO_TARGET_H__
#define LEETCODE_PROBLEMS_SUM_OF_MUTATED_ARRAY_CLOSEST_TO_TARGET_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1300 {

using Func = std::function<int(std::vector<int>&, int)>;

class SumOfMutatedArrayClosestToTargetSolution
    : public SolutionBase<Func> {
 public:
  int findBestValue(std::vector<int>& arr, int target);

  SumOfMutatedArrayClosestToTargetSolution();
};

}  // namespace problem_1300
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_MUTATED_ARRAY_CLOSEST_TO_TARGET_H__
