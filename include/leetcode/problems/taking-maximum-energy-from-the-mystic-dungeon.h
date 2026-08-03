
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3147 {

using Func = std::function<int(vector<int>&, int)>;

class TakingMaximumEnergyFromTheMysticDungeonSolution
    : public SolutionBase<Func> {
 public:
  //! 3147. Taking Maximum Energy From the Mystic Dungeon
  //! https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
  int maximumEnergy(vector<int>& energy, int k);

  TakingMaximumEnergyFromTheMysticDungeonSolution();
};

}  // namespace problem_3147
}  // namespace leetcode
