#ifndef LEETCODE_PROBLEMS_MAXIMUM_ENEMY_FORTS_THAT_CAN_BE_CAPTURED_H__
#define LEETCODE_PROBLEMS_MAXIMUM_ENEMY_FORTS_THAT_CAN_BE_CAPTURED_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2511 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumEnemyFortsThatCanBeCapturedSolution
    : public SolutionBase<Func> {
 public:
  MaximumEnemyFortsThatCanBeCapturedSolution();

  int captureForts(std::vector<int>& forts);
};

}  // namespace problem_2511
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ENEMY_FORTS_THAT_CAN_BE_CAPTURED_H__
