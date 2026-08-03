#ifndef LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_TRAVERSAL_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2709 {

using Func = std::function<bool(std::vector<int>&)>;

class GreatestCommonDivisorTraversalSolution
    : public SolutionBase<Func> {
 public:
  GreatestCommonDivisorTraversalSolution();

  bool canTraverseAllPairs(std::vector<int>& nums);
};

}  // namespace problem_2709
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GREATEST_COMMON_DIVISOR_TRAVERSAL_H__
