#ifndef LEETCODE_PROBLEMS_MAXIMIZE_CYCLIC_PARTITION_SCORE_H_
#define LEETCODE_PROBLEMS_MAXIMIZE_CYCLIC_PARTITION_SCORE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3743 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MaximizeCyclicPartitionScoreSolution : public SolutionBase<Func> {
 public:
  MaximizeCyclicPartitionScoreSolution();

  long long maximumScore(std::vector<int>& nums, int k);
};

}  // namespace problem_3743
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_CYCLIC_PARTITION_SCORE_H_
