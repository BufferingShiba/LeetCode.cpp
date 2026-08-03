#ifndef LEETCODE_PROBLEMS_REORDERED_POWER_OF_2_H_
#define LEETCODE_PROBLEMS_REORDERED_POWER_OF_2_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_869 {

using Func = std::function<bool(int)>;

class ReorderedPowerOf2Solution : public SolutionBase<Func> {
 public:
  ReorderedPowerOf2Solution();

  bool reorderedPowerOf2(int n) {
    return getSolution()(n);
  }
};

}  // namespace problem_869
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REORDERED_POWER_OF_2_H_
