#ifndef LEETCODE_PROBLEM_882_H
#define LEETCODE_PROBLEM_882_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_882 {

using Func = std::function<int(std::vector<std::vector<int>>&, int, int)>;

class ReachableNodesInSubdividedGraphSolution : public SolutionBase<Func> {
 public:
  ReachableNodesInSubdividedGraphSolution();

  int reachableNodes(std::vector<std::vector<int>>& edges, int maxMoves, int n);
};

}  // namespace problem_882
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_882_H
