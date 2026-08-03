#ifndef LEETCODE_PROBLEMS_COUNT_COVERED_BUILDINGS_H
#define LEETCODE_PROBLEMS_COUNT_COVERED_BUILDINGS_H

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3531 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class CountCoveredBuildingsSolution : public SolutionBase<Func> {
public:
    CountCoveredBuildingsSolution();
    int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings);
};

}  // namespace leetcode::problem_3531

#endif  // LEETCODE_PROBLEMS_COUNT_COVERED_BUILDINGS_H
