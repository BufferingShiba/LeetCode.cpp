#include "leetcode/core.h"

namespace leetcode {
namespace problem_2568 {

using Func = std::function<int(vector<int>&)>;

class MinimumImpossibleOrSolution : public SolutionBase<Func> {
 public:
  //! 2568. Minimum Impossible OR
  //! https://leetcode.com/problems/minimum-impossible-or/
  int minImpossibleOR(vector<int>& nums);

  MinimumImpossibleOrSolution();
};

}  // namespace problem_2568
}  // namespace leetcode
