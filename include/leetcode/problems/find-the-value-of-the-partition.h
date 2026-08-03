
#include "leetcode/core.h"

namespace leetcode {
namespace problem_2740 {

using Func = std::function<int(vector<int>&)>;

class FindTheValueOfThePartitionSolution : public SolutionBase<Func> {
 public:
  //! 2740. Find the Value of the Partition
  //! https://leetcode.com/problems/find-the-value-of-the-partition/
  int findValueOfPartition(vector<int>& nums);

  FindTheValueOfThePartitionSolution();
};

}  // namespace problem_2740
}  // namespace leetcode
