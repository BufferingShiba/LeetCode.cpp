#ifndef LEETCODE_LAST_STONE_WEIGHT_H__
#define LEETCODE_LAST_STONE_WEIGHT_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1046 {

using Func = std::function<int(std::vector<int>&)>;

class LastStoneWeightSolution : public SolutionBase<Func> {
 public:
  LastStoneWeightSolution();

  int lastStoneWeight(std::vector<int>& stones);
};

}  // namespace problem_1046
}  // namespace leetcode

#endif  // LEETCODE_LAST_STONE_WEIGHT_H__
