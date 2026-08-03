#ifndef LEETCODE_PROBLEMS_MAXIMIZE_EXPRESSION_OF_THREE_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_EXPRESSION_OF_THREE_ELEMENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3745 {

using Func = std::function<int(std::vector<int>&)>;

class MaximizeExpressionOfThreeElementsSolution
    : public SolutionBase<Func> {
 public:
  MaximizeExpressionOfThreeElementsSolution();

  int maximizeExpressionOfThree(std::vector<int>& nums);
};

}  // namespace problem_3745
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_EXPRESSION_OF_THREE_ELEMENTS_H__
