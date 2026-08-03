#ifndef LEETCODE_PROBLEMS_MAXIMUM_NESTING_DEPTH_OF_THE_PARENTHESES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NESTING_DEPTH_OF_THE_PARENTHESES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1614 {

using Func = std::function<int(std::string)>;

class MaximumNestingDepthOfTheParenthesesSolution
    : public SolutionBase<Func> {
 public:
  MaximumNestingDepthOfTheParenthesesSolution();

  int maxDepth(std::string s);
};

}  // namespace problem_1614
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NESTING_DEPTH_OF_THE_PARENTHESES_H__
