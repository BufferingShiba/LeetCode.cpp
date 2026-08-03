#ifndef LEETCODE_PROBLEMS_SQUARES_OF_A_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_SQUARES_OF_A_SORTED_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_977 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SquaresOfASortedArraySolution
    : public SolutionBase<Func> {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums);

    SquaresOfASortedArraySolution();
};

}  // namespace leetcode::problem_977

#endif  // LEETCODE_PROBLEMS_SQUARES_OF_A_SORTED_ARRAY_H__
