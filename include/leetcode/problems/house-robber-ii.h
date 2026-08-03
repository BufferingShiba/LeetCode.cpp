#ifndef LEETCODE_HOUSE_ROBBER_II_H
#define LEETCODE_HOUSE_ROBBER_II_H

#include "leetcode/core.h"
#include <vector>

namespace leetcode::problem_213 {

using Func = std::function<int(std::vector<int>&)>;

class HouseRobberIiSolution : public SolutionBase<Func> {
public:
    HouseRobberIiSolution();
    int rob(std::vector<int>& nums);
};

} // namespace leetcode::problem_213

#endif
