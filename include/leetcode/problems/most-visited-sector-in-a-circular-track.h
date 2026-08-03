#ifndef LEETCODE_PROBLEMS_MOST_VISITED_SECTOR_IN_A_CIRCULAR_TRACK_H__
#define LEETCODE_PROBLEMS_MOST_VISITED_SECTOR_IN_A_CIRCULAR_TRACK_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1560 {

using Func = std::function<std::vector<int>(int, std::vector<int>&)>;

class MostVisitedSectorInACircularTrackSolution
    : public SolutionBase<Func> {
 public:
  MostVisitedSectorInACircularTrackSolution();

  std::vector<int> mostVisited(int n, std::vector<int>& rounds);
};

}  // namespace leetcode::problem_1560

#endif  // LEETCODE_PROBLEMS_MOST_VISITED_SECTOR_IN_A_CIRCULAR_TRACK_H__
