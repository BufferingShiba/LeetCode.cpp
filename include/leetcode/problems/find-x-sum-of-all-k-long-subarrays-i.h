#ifndef LEETCODE_PROBLEM_3318_H
#define LEETCODE_PROBLEM_3318_H

#include "leetcode/core.h"

namespace leetcode::problem_3318 {

using Func = std::function<std::vector<int>(std::vector<int>&, int, int)>;

class FindXSumOfAllKLongSubarraysISolution : public SolutionBase<Func> {
 public:
    FindXSumOfAllKLongSubarraysISolution();

    std::vector<int> findXSum(std::vector<int>& nums, int k, int x);
};

}  // namespace leetcode::problem_3318

#endif
