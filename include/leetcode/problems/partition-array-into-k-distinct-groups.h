#include "leetcode/core.h"

namespace leetcode {
namespace problem_3659 {

using Func = std::function<bool(vector<int>&, int)>;

class PartitionArrayIntoKDistinctGroupsSolution : public SolutionBase<Func> {
 public:
  //! 3659. Partition Array Into K-Distinct Groups
  //! https://leetcode.com/problems/partition-array-into-k-distinct-groups/
  bool partitionArray(vector<int>& nums, int k);

  PartitionArrayIntoKDistinctGroupsSolution();
};

}  // namespace problem_3659
}  // namespace leetcode
