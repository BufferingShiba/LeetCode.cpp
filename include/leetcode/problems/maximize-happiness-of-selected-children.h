#include "leetcode/core.h"

namespace leetcode {
namespace problem_3075 {

using Func = std::function<long long(vector<int>&, int)>;

class MaximizeHappinessOfSelectedChildrenSolution : public SolutionBase<Func> {
 public:
  //! 3075. Maximize Happiness of Selected Children
  //! https://leetcode.com/problems/maximize-happiness-of-selected-children/
  long long maximumHappinessSum(vector<int>& happiness, int k);

  MaximizeHappinessOfSelectedChildrenSolution();
};

}  // namespace problem_3075
}  // namespace leetcode