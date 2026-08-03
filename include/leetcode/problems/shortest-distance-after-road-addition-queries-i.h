#pragma once
#include "leetcode/core.h"

namespace leetcode::problem_3243 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class ShortestDistanceAfterRoadAdditionQueriesISolution : public SolutionBase<Func> {
public:
    ShortestDistanceAfterRoadAdditionQueriesISolution();
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries);
};

} // namespace leetcode::problem_3243
