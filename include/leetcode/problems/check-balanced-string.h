#ifndef LEETCODE_PROBLEMS_CHECK_BALANCED_STRING_H__
#define LEETCODE_PROBLEMS_CHECK_BALANCED_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3340 {

using Func = std::function<bool(std::string)>;

class CheckBalancedStringSolution : public SolutionBase<Func> {
 public:
  CheckBalancedStringSolution();

  bool isBalanced(std::string num);
};

}  // namespace problem_3340
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_BALANCED_STRING_H__
