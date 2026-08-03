#ifndef LEETCODE_PROBLEMS_PAINTING_THE_WALLS_H__
#define LEETCODE_PROBLEMS_PAINTING_THE_WALLS_H__

#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2742 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class PaintingTheWallsSolution : public SolutionBase<Func> {
public:
    PaintingTheWallsSolution();

    int paintWalls(std::vector<int>& cost, std::vector<int>& time);
};

}  // namespace leetcode::problem_2742

#endif  // LEETCODE_PROBLEMS_PAINTING_THE_WALLS_H__
