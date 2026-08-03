#ifndef LEETCODE_PROBLEMS_PARTITION_ARRAY_FOR_MAXIMUM_XOR_AND_AND_H__
#define LEETCODE_PROBLEMS_PARTITION_ARRAY_FOR_MAXIMUM_XOR_AND_AND_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3630 {

using Func = std::function<long long(std::vector<int>&)>;

class PartitionArrayForMaximumXorAndAndSolution
    : public SolutionBase<Func> {
 public:
  PartitionArrayForMaximumXorAndAndSolution();

  long long maximizeXorAndXor(std::vector<int>& nums);
};

}  // namespace problem_3630
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PARTITION_ARRAY_FOR_MAXIMUM_XOR_AND_AND_H__
