#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_NON_OVERLAPPING_INTERVALS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_NON_OVERLAPPING_INTERVALS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3414 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class MaximumScoreOfNonOverlappingIntervalsSolution
    : public SolutionBase<Func> {
 public:
  MaximumScoreOfNonOverlappingIntervalsSolution();

  std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
    return getSolution()(intervals);
  }
};

}  // namespace problem_3414
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_NON_OVERLAPPING_INTERVALS_H__
