#ifndef LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_TWO_ARRAYS_TO_MINIMIZE_SUM_DIFFERENCE_H__
#define LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_TWO_ARRAYS_TO_MINIMIZE_SUM_DIFFERENCE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2035 {

using Func = std::function<int(std::vector<int>&)>;

class PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution
    : public SolutionBase<Func> {
 public:
  PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution();

  int minimumDifference(std::vector<int>& nums);
};

}  // namespace problem_2035
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PARTITION_ARRAY_INTO_TWO_ARRAYS_TO_MINIMIZE_SUM_DIFFERENCE_H__
