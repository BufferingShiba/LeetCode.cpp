#ifndef LEETCODE_PROBLEMS_K_DIFF_PAIRS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_K_DIFF_PAIRS_IN_AN_ARRAY_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_532 {

using Func = std::function<int(std::vector<int>&, int)>;

class KDiffPairsInAnArraySolution : public SolutionBase<Func> {
public:
    KDiffPairsInAnArraySolution();
    int findPairs(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_532

#endif  // LEETCODE_PROBLEMS_K_DIFF_PAIRS_IN_AN_ARRAY_H__
