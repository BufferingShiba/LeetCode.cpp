
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3218 {

using Func = std::function<int(int, int, std::vector<int>&, std::vector<int>&)>;

class MinimumCostForCuttingCakeISolution : public SolutionBase<Func> {
 public:
  //! 3218. Minimum Cost for Cutting Cake I
  //! https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/
  int minimumCost(int m, int n, std::vector<int>& horizontalCut,
                  std::vector<int>& verticalCut);

  MinimumCostForCuttingCakeISolution();
};

}  // namespace problem_3218
}  // namespace leetcode
