#ifndef LEETCODE_PROBLEMS_CHECK_IF_THE_NUMBER_IS_FASCINATING_H__
#define LEETCODE_PROBLEMS_CHECK_IF_THE_NUMBER_IS_FASCINATING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2729 {

using Func = std::function<bool(int)>;

class CheckIfTheNumberIsFascinatingSolution
    : public SolutionBase<Func> {
 public:
  CheckIfTheNumberIsFascinatingSolution();

  bool isFascinating(int n);
};

}  // namespace problem_2729
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_THE_NUMBER_IS_FASCINATING_H__
