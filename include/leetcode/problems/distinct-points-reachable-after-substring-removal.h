#ifndef LEETCODE_PROBLEMS_DISTINCT_POINTS_REACHABLE_AFTER_SUBSTRING_REMOVAL_H__
#define LEETCODE_PROBLEMS_DISTINCT_POINTS_REACHABLE_AFTER_SUBSTRING_REMOVAL_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3694 {

using Func = std::function<int(std::string, int)>;

class DistinctPointsReachableAfterSubstringRemovalSolution
    : public SolutionBase<Func> {
 public:
  DistinctPointsReachableAfterSubstringRemovalSolution();

  int distinctPoints(std::string s, int k);
};

}  // namespace problem_3694
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DISTINCT_POINTS_REACHABLE_AFTER_SUBSTRING_REMOVAL_H__
