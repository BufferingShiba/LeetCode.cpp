#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VISIBLE_POINTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VISIBLE_POINTS_H__

#include "leetcode/core.h"

#include <cmath>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1610 {

using Func = std::function<int(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location)>;

class MaximumNumberOfVisiblePointsSolution : public SolutionBase<Func> {
public:
  MaximumNumberOfVisiblePointsSolution() {
    setMetaInfo({.id = 1610,
                 .title = "Maximum Number of Visible Points",
                 .url = "https://leetcode.com/problems/maximum-number-of-visible-points/"});
    registerStrategy(
        {.name = "AngleSortingSlidingWindow",
         .expected = "Accepted",
         .time_complexity = "O(n log n)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Math", "Geometry", "Sliding Window", "Sorting"},
         .notes = "Compute angles via atan2, duplicate array for circular sliding window."},
        visiblePointsImpl);
  }

  int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
    return getSolution()(points, angle, location);
  }

private:
  static int visiblePointsImpl(std::vector<std::vector<int>>& points, int angle,
                               std::vector<int>& location);
};

}  // namespace problem_1610
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_VISIBLE_POINTS_H__
