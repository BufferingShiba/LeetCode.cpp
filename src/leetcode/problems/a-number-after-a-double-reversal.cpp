#include "leetcode/problems/a-number-after-a-double-reversal.h"

namespace leetcode {
namespace problem_2119 {

namespace {

bool isSameAfterReversalsImpl(int num) {
  // Reversal drops trailing zeros unless num itself is zero.
  return num == 0 || num % 10 != 0;
}

}  // namespace

ANumberAfterADoubleReversalSolution::ANumberAfterADoubleReversalSolution() {
  setMetaInfo({.id = 2119,
               .title = "A Number After a Double Reversal",
               .url = "https://leetcode.com/problems/a-number-after-a-double-reversal/"});
  registerStrategy({.name = "MathTrailingZero",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   isSameAfterReversalsImpl);
}

bool ANumberAfterADoubleReversalSolution::isSameAfterReversals(int num) {
  return getSolution()(num);
}

}  // namespace problem_2119
}  // namespace leetcode
