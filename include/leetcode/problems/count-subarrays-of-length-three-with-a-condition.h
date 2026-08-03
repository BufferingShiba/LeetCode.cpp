#ifndef LEETCODE_PROBLEMS_COUNT_SUBARRAYS_OF_LENGTH_THREE_WITH_A_CONDITION_H__
#define LEETCODE_PROBLEMS_COUNT_SUBARRAYS_OF_LENGTH_THREE_WITH_A_CONDITION_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3392 {

using Func = std::function<int(std::vector<int>&)>;

class CountSubarraysOfLengthThreeWithAConditionSolution : public SolutionBase<Func> {
public:
    CountSubarraysOfLengthThreeWithAConditionSolution();

    int countSubarrays(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3392

#endif  // LEETCODE_PROBLEMS_COUNT_SUBARRAYS_OF_LENGTH_THREE_WITH_A_CONDITION_H__
