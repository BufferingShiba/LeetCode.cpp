#ifndef LEETCODE_PROBLEM_MINIMUM_THRESHOLD_PATH_WITH_LIMITED_HEAVY_EDGES_H
#define LEETCODE_PROBLEM_MINIMUM_THRESHOLD_PATH_WITH_LIMITED_HEAVY_EDGES_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3924 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int, int, int)>;

class MinimumThresholdPathWithLimitedHeavyEdgesSolution : public SolutionBase<Func> {
 public:
  MinimumThresholdPathWithLimitedHeavyEdgesSolution();

  int minimumThreshold(int n, std::vector<std::vector<int>>& edges, int source,
                       int target, int k);
};

}  // namespace problem_3924
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_MINIMUM_THRESHOLD_PATH_WITH_LIMITED_HEAVY_EDGES_H
