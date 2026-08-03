#ifndef LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H__
#define LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1026 {

using Func = std::function<int(TreeNode*)>;

class MaximumDifferenceBetweenNodeAndAncestorSolution
    : public SolutionBase<Func> {
 public:
  MaximumDifferenceBetweenNodeAndAncestorSolution() { registerStrategy(); }

  int maxAncestorDiff(TreeNode* root);

 protected:
  void registerStrategy();
};

}  // namespace problem_1026
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H__
