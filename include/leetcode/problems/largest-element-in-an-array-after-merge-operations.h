#ifndef LEETCODE_PROBLEMS_LARGEST_ELEMENT_IN_AN_ARRAY_AFTER_MERGE_OPERATIONS_H__
#define LEETCODE_PROBLEMS_LARGEST_ELEMENT_IN_AN_ARRAY_AFTER_MERGE_OPERATIONS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2789 {

using Func = std::function<long long(std::vector<int>&)>;

class LargestElementInAnArrayAfterMergeOperationsSolution
    : public SolutionBase<Func> {
 public:
  LargestElementInAnArrayAfterMergeOperationsSolution();

  long long maxArrayValue(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2789

#endif  // LEETCODE_PROBLEMS_LARGEST_ELEMENT_IN_AN_ARRAY_AFTER_MERGE_OPERATIONS_H__
