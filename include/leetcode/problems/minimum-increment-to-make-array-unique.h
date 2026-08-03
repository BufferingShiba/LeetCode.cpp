#include "leetcode/core.h"

namespace leetcode {
namespace problem_945 {

using Func = std::function<int(vector<int>&)>;

class MinimumIncrementToMakeArrayUniqueSolution : public SolutionBase<Func> {
 public:
  //! 945. Minimum Increment to Make Array Unique
  //! https://leetcode.com/problems/minimum-increment-to-make-array-unique/
  int minIncrementForUnique(vector<int>& nums);

  MinimumIncrementToMakeArrayUniqueSolution();
};

}  // namespace problem_945
}  // namespace leetcode
