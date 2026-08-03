#ifndef LEETCODE_PROBLEMS_FILTER_OCCUPIED_INTERVALS_H_
#define LEETCODE_PROBLEMS_FILTER_OCCUPIED_INTERVALS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3975 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, int, int)>;

class FilterOccupiedIntervalsSolution : public SolutionBase<Func> {
 public:
  FilterOccupiedIntervalsSolution();

  std::vector<std::vector<int>> filterOccupiedIntervals(
      std::vector<std::vector<int>>& occupiedIntervals, int freeStart,
      int freeEnd);
};

}  // namespace problem_3975
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FILTER_OCCUPIED_INTERVALS_H_
