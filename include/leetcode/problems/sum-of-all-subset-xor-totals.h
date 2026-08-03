#ifndef LEETCODE_PROBLEMS_SUM_OF_ALL_SUBSET_XOR_TOTALS_H__
#define LEETCODE_PROBLEMS_SUM_OF_ALL_SUBSET_XOR_TOTALS_H__

#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1863 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfAllSubsetXorTotalsSolution
    : public SolutionBase<Func> {
 public:
  SumOfAllSubsetXorTotalsSolution();

  int subsetXORSum(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1863

#endif  // LEETCODE_PROBLEMS_SUM_OF_ALL_SUBSET_XOR_TOTALS_H__
