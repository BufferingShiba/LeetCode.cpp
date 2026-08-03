#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_PARTITIONS_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_PARTITIONS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2963 {

using Func = std::function<int(std::vector<int>&)>;

class CountTheNumberOfGoodPartitionsSolution
    : public SolutionBase<Func> {
 public:
  CountTheNumberOfGoodPartitionsSolution();

  int numberOfGoodPartitions(std::vector<int>& nums);
};

}  // namespace problem_2963
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_PARTITIONS_H__
