#include "leetcode/core.h"

namespace leetcode {
namespace problem_3649 {

using Func = std::function<long(vector<int>&)>;

class NumberOfPerfectPairsSolution : public SolutionBase<Func> {
 public:
  //! 3649. Number of Perfect Pairs
  //! https://leetcode.com/problems/number-of-perfect-pairs/
  long perfectPairs(vector<int>& nums);

  NumberOfPerfectPairsSolution();
};

}  // namespace problem_3649
}  // namespace leetcode
