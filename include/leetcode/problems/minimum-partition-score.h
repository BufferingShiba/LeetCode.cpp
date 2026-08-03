#ifndef LEETCODE_PROBLEMS_MINIMUM_PARTITION_SCORE_H__
#define LEETCODE_PROBLEMS_MINIMUM_PARTITION_SCORE_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3826 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MinimumPartitionScoreSolution : public SolutionBase<Func> {
 public:
  MinimumPartitionScoreSolution();
  long long minPartitionScore(std::vector<int>& nums, int k);
};

}  // namespace problem_3826
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_PARTITION_SCORE_H__
