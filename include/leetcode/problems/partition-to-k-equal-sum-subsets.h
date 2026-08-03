#ifndef LEETCODE_PROBLEMS_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H__
#define LEETCODE_PROBLEMS_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H__

#include <functional>
#include <vector>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_698 {

using Func = std::function<bool(std::vector<int>&, int)>;

class PartitionToKEqualSumSubsetsSolution : public SolutionBase<Func> {
 public:
  PartitionToKEqualSumSubsetsSolution();
  bool canPartitionKSubsets(std::vector<int>& nums, int k);
};

}  // namespace problem_698
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H__
