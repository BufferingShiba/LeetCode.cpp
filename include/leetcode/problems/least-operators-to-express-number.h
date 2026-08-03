#ifndef LEETCODE_PROBLEMS_LEAST_OPERATORS_TO_EXPRESS_NUMBER_H__
#define LEETCODE_PROBLEMS_LEAST_OPERATORS_TO_EXPRESS_NUMBER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_964 {

class LeastOperatorsToExpressNumberSolution
    : public SolutionBase<std::function<int(int, int)>> {
 public:
  LeastOperatorsToExpressNumberSolution() {
    setMetaInfo({.id = 964,
                 .title = "Least Operators to Express Number",
                 .url = "https://leetcode.com/problems/least-operators-to-express-number/"});
    registerStrategy(
        {.name = "digit-dp-memo",
         .expected = "Accepted",
         .time_complexity = "O(T)",
         .space_complexity = "O(T)",
         .tags = {"Math", "Dynamic Programming", "Memoization"}},
        leastOpsExpressTargetImpl);
  }

  int leastOpsExpressTarget(int x, int target) {
    return getSolution()(x, target);
  }

 private:
  static int leastOpsExpressTargetImpl(int x, int target);
};

}  // namespace problem_964
}  // namespace leetcode

#endif
