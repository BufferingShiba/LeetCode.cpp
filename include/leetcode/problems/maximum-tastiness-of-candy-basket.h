#include "leetcode/core.h"

namespace leetcode {
namespace problem_2517 {

using Func = std::function<int(vector<int>&, int)>;

class MaximumTastinessOfCandyBasketSolution : public SolutionBase<Func> {
 public:
  //! 2517. Maximum Tastiness of Candy Basket
  //! https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
  int maximumTastiness(vector<int>& price, int k);

  MaximumTastinessOfCandyBasketSolution();
};

}  // namespace problem_2517
}  // namespace leetcode
