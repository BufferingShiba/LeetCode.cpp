#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_GAME_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_GAME_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2974 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MinimumNumberGameSolution : public SolutionBase<Func> {
public:
    MinimumNumberGameSolution();

    std::vector<int> numberGame(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2974

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_GAME_H__
