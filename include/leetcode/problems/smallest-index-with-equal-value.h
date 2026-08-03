#ifndef LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_EQUAL_VALUE_H__
#define LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_EQUAL_VALUE_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2057 {

using Func = std::function<int(std::vector<int>&)>;

class SmallestIndexWithEqualValueSolution : public SolutionBase<Func> {
public:
    SmallestIndexWithEqualValueSolution();
    int smallestEqual(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2057

#endif  // LEETCODE_PROBLEMS_SMALLEST_INDEX_WITH_EQUAL_VALUE_H__
