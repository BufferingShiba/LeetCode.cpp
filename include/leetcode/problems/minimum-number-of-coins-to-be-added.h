
#include "leetcode/core.h"

namespace leetcode {
namespace problem_2952 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumNumberOfCoinsToBeAddedSolution : public SolutionBase<Func> {
 public:
  //! 2952. Minimum Number of Coins to be Added
  //! https://leetcode.com/problems/minimum-number-of-coins-to-be-added/
  int minimumAddedCoins(std::vector<int>& coins, int target);

  MinimumNumberOfCoinsToBeAddedSolution();
};

}  // namespace problem_2952
}  // namespace leetcode
