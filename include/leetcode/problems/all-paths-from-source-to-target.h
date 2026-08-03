#ifndef LEETCODE_PROBLEMS_ALL_PATHS_FROM_SOURCE_TO_TARGET_H__
#define LEETCODE_PROBLEMS_ALL_PATHS_FROM_SOURCE_TO_TARGET_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_797 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class AllPathsFromSourceToTargetSolution
    : public SolutionBase<Func> {
 public:
  AllPathsFromSourceToTargetSolution();

  std::vector<std::vector<int>> allPathsSourceTarget(
      std::vector<std::vector<int>>& graph);
};

}  // namespace leetcode::problem_797

#endif  // LEETCODE_PROBLEMS_ALL_PATHS_FROM_SOURCE_TO_TARGET_H__
