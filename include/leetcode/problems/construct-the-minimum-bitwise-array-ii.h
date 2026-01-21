#include "leetcode/core.h"

namespace leetcode {
namespace problem_3315 {

using Func = std::function<vector<int>(vector<int>&)>;

class ConstructTheMinimumBitwiseArrayIiSolution : public SolutionBase<Func> {
 public:
  //! 3315. Construct the Minimum Bitwise Array II
  //! https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
  vector<int> minBitwiseArray(vector<int>& nums);

  ConstructTheMinimumBitwiseArrayIiSolution();
};

}  // namespace problem_3315
}  // namespace leetcode