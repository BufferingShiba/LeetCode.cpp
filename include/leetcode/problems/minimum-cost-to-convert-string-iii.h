#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_CONVERT_STRING_III_H
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_CONVERT_STRING_III_H

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3995 {

using Func = std::function<int(std::string, std::string, std::vector<std::vector<std::string>>&, std::vector<int>&)>;

class MinimumCostToConvertStringIiiSolution
    : public SolutionBase<Func> {
public:
    MinimumCostToConvertStringIiiSolution();

    int minCost(std::string source, std::string target,
                std::vector<std::vector<std::string>>& rules,
                std::vector<int>& costs);
};

}  // namespace problem_3995
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_CONVERT_STRING_III_H
