#ifndef LEETCODE_PROBLEMS_POWER_OF_FOUR_H__
#define LEETCODE_PROBLEMS_POWER_OF_FOUR_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_342 {

using Func = std::function<bool(int)>;

class PowerOfFourSolution : public SolutionBase<Func> {
 public:
  PowerOfFourSolution();

  bool isPowerOfFour(int n);
};

}  // namespace problem_342
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POWER_OF_FOUR_H__
