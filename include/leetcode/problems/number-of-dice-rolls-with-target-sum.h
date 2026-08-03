#ifndef LEETCODE_PROBLEMS_NUMBER_OF_DICE_ROLLS_WITH_TARGET_SUM_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_DICE_ROLLS_WITH_TARGET_SUM_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1155 {

using Func = std::function<int(int, int, int)>;

class NumberOfDiceRollsWithTargetSumSolution : public SolutionBase<Func> {
 public:
  NumberOfDiceRollsWithTargetSumSolution();

  int numRollsToTarget(int n, int k, int target);
};

}  // namespace problem_1155
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_DICE_ROLLS_WITH_TARGET_SUM_H_
