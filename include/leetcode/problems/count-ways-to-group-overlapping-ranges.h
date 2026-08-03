#ifndef LEETCODE_PROBLEMS_COUNT_WAYS_TO_GROUP_OVERLAPPING_RANGES_H__
#define LEETCODE_PROBLEMS_COUNT_WAYS_TO_GROUP_OVERLAPPING_RANGES_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2580 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountWaysToGroupOverlappingRangesSolution
    : public SolutionBase<Func> {
public:
    CountWaysToGroupOverlappingRangesSolution();

    int countWays(std::vector<std::vector<int>>& ranges);
};

}  // namespace leetcode::problem_2580

#endif  // LEETCODE_PROBLEMS_COUNT_WAYS_TO_GROUP_OVERLAPPING_RANGES_H__
