#ifndef LEETCODE_PROBLEMS_INTERVAL_LIST_INTERSECTIONS_H__
#define LEETCODE_PROBLEMS_INTERVAL_LIST_INTERSECTIONS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_986 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class IntervalListIntersectionsSolution
    : public SolutionBase<Func> {
 public:
  IntervalListIntersectionsSolution();

  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList);
};

}  // namespace problem_986
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INTERVAL_LIST_INTERSECTIONS_H__
