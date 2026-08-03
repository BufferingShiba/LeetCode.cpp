#ifndef LEETCODE_PROBLEM_2226_H__
#define LEETCODE_PROBLEM_2226_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2226 {

using MaximumCandiesFunc =
    std::function<int(std::vector<int>&, long long)>;

class MaximumCandiesAllocatedToKChildrenSolution
    : public SolutionBase<MaximumCandiesFunc> {
public:
    MaximumCandiesAllocatedToKChildrenSolution();
    int maximumCandies(std::vector<int>& candies, long long k);
};

}  // namespace leetcode::problem_2226

#endif  // LEETCODE_PROBLEM_2226_H__
