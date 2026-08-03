#ifndef LEETCODE_PROBLEMS_POWER_OF_THREE_H__
#define LEETCODE_PROBLEMS_POWER_OF_THREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_326 {

using Func = std::function<bool(int)>;

class PowerOfThreeSolution : public SolutionBase<Func> {
 public:
  PowerOfThreeSolution();

  bool isPowerOfThree(int n);
};

}  // namespace problem_326
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POWER_OF_THREE_H__
