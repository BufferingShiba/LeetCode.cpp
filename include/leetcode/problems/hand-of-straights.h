#ifndef LEETCODE_PROBLEMS_HAND_OF_STRAIGHTS_H_
#define LEETCODE_PROBLEMS_HAND_OF_STRAIGHTS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_846 {

using Func = std::function<bool(std::vector<int>&, int)>;

class HandOfStraightsSolution : public SolutionBase<Func> {
 public:
  HandOfStraightsSolution();

  bool isNStraightHand(std::vector<int>& hand, int groupSize);
};

}  // namespace leetcode::problem_846

#endif  // LEETCODE_PROBLEMS_HAND_OF_STRAIGHTS_H_
