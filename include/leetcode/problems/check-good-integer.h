#ifndef LEETCODE_PROBLEMS_CHECK_GOOD_INTEGER_H_
#define LEETCODE_PROBLEMS_CHECK_GOOD_INTEGER_H_

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_3959 {

using Func = std::function<bool(int)>;

class CheckGoodIntegerSolution : public SolutionBase<Func> {
 public:
  CheckGoodIntegerSolution();

  bool checkGoodInteger(int n);
};

}  // namespace problem_3959
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_GOOD_INTEGER_H_
