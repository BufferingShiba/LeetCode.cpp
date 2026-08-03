#ifndef LEETCODE_PROBLEMS_K_CONCATENATION_MAXIMUM_SUM_H__
#define LEETCODE_PROBLEMS_K_CONCATENATION_MAXIMUM_SUM_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1191 {

using Func = std::function<int(std::vector<int>&, int)>;

class KConcatenationMaximumSumSolution : public SolutionBase<Func> {
public:
    KConcatenationMaximumSumSolution();

    int kConcatenationMaxSum(std::vector<int>& arr, int k);
};

}  // namespace leetcode::problem_1191

#endif  // LEETCODE_PROBLEMS_K_CONCATENATION_MAXIMUM_SUM_H__
