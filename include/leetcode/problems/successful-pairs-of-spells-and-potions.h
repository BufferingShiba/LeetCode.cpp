#include "leetcode/core.h"

namespace leetcode {
namespace problem_2300 {

using Func = std::function<vector<int>(vector<int>&, vector<int>&, long long)>;

class SuccessfulPairsOfSpellsAndPotionsSolution : public SolutionBase<Func> {
 public:
  //! 2300. Successful Pairs of Spells and Potions
  //! https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success);

  SuccessfulPairsOfSpellsAndPotionsSolution();
};

}  // namespace problem_2300
}  // namespace leetcode
