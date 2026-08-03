#include "leetcode/core.h"

namespace leetcode {
namespace problem_2780 {

using Func = std::function<int(vector<int>&)>;

class MinimumIndexOfAValidSplitSolution : public SolutionBase<Func> {
 public:
  //! 2780. Minimum Index of a Valid Split
  //! https://leetcode.com/problems/minimum-index-of-a-valid-split/
  int minimumIndex(vector<int>& nums);

  MinimumIndexOfAValidSplitSolution();
};

}  // namespace problem_2780
}  // namespace leetcode
