#ifndef LEETCODE_PROBLEMS_ARRAY_PARTITION_H__
#define LEETCODE_PROBLEMS_ARRAY_PARTITION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_561 {

using Func = std::function<int(std::vector<int>&)>;

class ArrayPartitionSolution : public SolutionBase<Func> {
 public:
  ArrayPartitionSolution();

  int arrayPairSum(std::vector<int>& nums);
};

}  // namespace problem_561
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ARRAY_PARTITION_H__
