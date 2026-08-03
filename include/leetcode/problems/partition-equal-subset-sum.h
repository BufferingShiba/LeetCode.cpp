#include "leetcode/core.h"

namespace leetcode {
namespace problem_416 {

using Func = std::function<bool(vector<int>&)>;

class PartitionEqualSubsetSumSolution : public SolutionBase<Func> {
 public:
  //! 416. Partition Equal Subset Sum
  //! https://leetcode.com/problems/partition-equal-subset-sum/
  bool canPartition(vector<int>& nums);

  PartitionEqualSubsetSumSolution();
};

}  // namespace problem_416
}  // namespace leetcode
