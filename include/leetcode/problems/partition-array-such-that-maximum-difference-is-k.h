#ifndef LEETCODE_PROBLEMS_PARTITION_ARRAY_SUCH_THAT_MAXIMUM_DIFFERENCE_IS_K_H__
#define LEETCODE_PROBLEMS_PARTITION_ARRAY_SUCH_THAT_MAXIMUM_DIFFERENCE_IS_K_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2294 {

using Func = std::function<int(std::vector<int>&, int)>;

class PartitionArraySuchThatMaximumDifferenceIsKSolution
    : public SolutionBase<Func> {
 public:
  PartitionArraySuchThatMaximumDifferenceIsKSolution();

  int partitionArray(std::vector<int>& nums, int k);
};

}  // namespace problem_2294
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PARTITION_ARRAY_SUCH_THAT_MAXIMUM_DIFFERENCE_IS_K_H__
