#ifndef LEETCODE_PROBLEM_803_H
#define LEETCODE_PROBLEM_803_H

#include "leetcode/core.h"

namespace leetcode::problem_803 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class BricksFallingWhenHitSolution : public SolutionBase<Func> {
 public:
    BricksFallingWhenHitSolution();
    std::vector<int> hitBricks(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& hits);
};

}  // namespace leetcode::problem_803

#endif
