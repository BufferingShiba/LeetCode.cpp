#ifndef LEETCODE_PROBLEMS_MAXIMUM_WEIGHTED_K_EDGE_PATH_H__
#define LEETCODE_PROBLEMS_MAXIMUM_WEIGHTED_K_EDGE_PATH_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3543 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int, int)>;

class MaximumWeightedKEdgePathSolution
    : public SolutionBase<Func> {
 public:
  MaximumWeightedKEdgePathSolution();

  int maxWeight(int n, std::vector<std::vector<int>>& edges, int k, int t);
};

}  // namespace problem_3543
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_WEIGHTED_K_EDGE_PATH_H__
