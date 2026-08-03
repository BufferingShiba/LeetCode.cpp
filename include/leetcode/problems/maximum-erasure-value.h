#ifndef LEETCODE_PROBLEMS_MAXIMUM_ERASURE_VALUE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_ERASURE_VALUE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1695 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumErasureValueSolution : public SolutionBase<Func> {
 public:
    MaximumErasureValueSolution();
    int maximumUniqueSubarray(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1695

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ERASURE_VALUE_H__
