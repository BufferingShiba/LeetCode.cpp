#ifndef LEETCODE_PROBLEMS_SHUFFLE_THE_ARRAY_H__
#define LEETCODE_PROBLEMS_SHUFFLE_THE_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1470 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class ShuffleTheArraySolution : public SolutionBase<Func> {
public:
    ShuffleTheArraySolution();

    std::vector<int> shuffle(std::vector<int>& nums, int n);
};

}  // namespace leetcode::problem_1470

#endif  // LEETCODE_PROBLEMS_SHUFFLE_THE_ARRAY_H__
