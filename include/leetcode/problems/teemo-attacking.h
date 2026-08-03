#ifndef LEETCODE_PROBLEMS_TEEMO_ATTACKING_H__
#define LEETCODE_PROBLEMS_TEEMO_ATTACKING_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_495 {

using Func = std::function<int(std::vector<int>&, int)>;

class TeemoAttackingSolution : public SolutionBase<Func> {
 public:
  TeemoAttackingSolution();

  int findPoisonedDuration(std::vector<int>& timeSeries, int duration);
};

}  // namespace problem_495
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TEEMO_ATTACKING_H__
