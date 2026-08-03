#ifndef LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_THREE_PARTS_WITH_EQUAL_SUM_H
#define LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_THREE_PARTS_WITH_EQUAL_SUM_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1013 {

using Func = std::function<bool(std::vector<int>&)>;

class PartitionArrayIntoThreePartsWithEqualSumSolution
    : public SolutionBase<Func> {
public:
    PartitionArrayIntoThreePartsWithEqualSumSolution();

    bool canThreePartsEqualSum(std::vector<int>& arr);
};

}  // namespace leetcode::problem_1013

#endif  // LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_THREE_PARTS_WITH_EQUAL_SUM_H
