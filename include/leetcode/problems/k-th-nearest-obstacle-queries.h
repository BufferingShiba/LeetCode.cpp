#ifndef LEETCODE_PROBLEM_3275_K_TH_NEAREST_OBSTACLE_QUERIES_H
#define LEETCODE_PROBLEM_3275_K_TH_NEAREST_OBSTACLE_QUERIES_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3275 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&, int)>;

class KThNearestObstacleQueriesSolution : public SolutionBase<Func> {
 public:
  KThNearestObstacleQueriesSolution();

  std::vector<int> resultsArray(std::vector<std::vector<int>>& queries, int k);
};

}  // namespace problem_3275
}  // namespace leetcode

#endif
