#ifndef LEETCODE_PROBLEMS_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1298 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&,
                                std::vector<std::vector<int>>&,
                                std::vector<std::vector<int>>&,
                                std::vector<int>&)>;

class MaximumCandiesYouCanGetFromBoxesSolution : public SolutionBase<Func> {
 public:
  MaximumCandiesYouCanGetFromBoxesSolution();

  int maxCandies(std::vector<int>& status, std::vector<int>& candies,
                 std::vector<std::vector<int>>& keys,
                 std::vector<std::vector<int>>& containedBoxes,
                 std::vector<int>& initialBoxes);
};

}  // namespace problem_1298
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H__
