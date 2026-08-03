#ifndef LEETCODE_PROBLEMS_NUMBER_OF_BIT_CHANGES_TO_MAKE_TWO_INTEGERS_EQUAL_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_BIT_CHANGES_TO_MAKE_TWO_INTEGERS_EQUAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3226 {

using Func = std::function<int(int, int)>;

class NumberOfBitChangesToMakeTwoIntegersEqualSolution
    : public SolutionBase<Func> {
 public:
  NumberOfBitChangesToMakeTwoIntegersEqualSolution();

  int minChanges(int n, int k);
};

}  // namespace problem_3226
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_BIT_CHANGES_TO_MAKE_TWO_INTEGERS_EQUAL_H__
