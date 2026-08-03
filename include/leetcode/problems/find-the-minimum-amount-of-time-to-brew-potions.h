
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3494 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&)>;

class FindTheMinimumAmountOfTimeToBrewPotionsSolution
    : public SolutionBase<Func> {
 public:
  //! 3494. Find the Minimum Amount of Time to Brew Potions
  //! https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/
  long long minTime(std::vector<int>& skill, std::vector<int>& mana);

  FindTheMinimumAmountOfTimeToBrewPotionsSolution();
};

}  // namespace problem_3494
}  // namespace leetcode
