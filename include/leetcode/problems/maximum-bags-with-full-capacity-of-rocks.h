#ifndef LEETCODE_PROBLEMS_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2279 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int)>;

class MaximumBagsWithFullCapacityOfRocksSolution
    : public SolutionBase<Func> {
 public:
  MaximumBagsWithFullCapacityOfRocksSolution();

  int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks,
                  int additionalRocks);
};

}  // namespace leetcode::problem_2279

#endif  // LEETCODE_PROBLEMS_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H__
