#ifndef LEETCODE_PROBLEM_2739_H
#define LEETCODE_PROBLEM_2739_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2739 {

using Func = std::function<int(int, int)>;

class TotalDistanceTraveledSolution : public SolutionBase<Func> {
 public:
  TotalDistanceTraveledSolution();

  int distanceTraveled(int mainTank, int additionalTank);
};

}  // namespace problem_2739
}  // namespace leetcode

#endif
