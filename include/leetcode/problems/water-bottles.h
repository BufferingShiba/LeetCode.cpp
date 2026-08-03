#ifndef LEETCODE_PROBLEM_1518_H__
#define LEETCODE_PROBLEM_1518_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1518 {

using Func = std::function<int(int, int)>;

class WaterBottlesSolution : public SolutionBase<Func> {
 public:
  WaterBottlesSolution();

  int numWaterBottles(int numBottles, int numExchange);
};

}  // namespace problem_1518
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1518_H__
