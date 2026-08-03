#ifndef LEETCODE_PROBLEM_2583_H_
#define LEETCODE_PROBLEM_2583_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2583 {

using Func = std::function<long long(TreeNode*, int)>;

class KthLargestSumInABinaryTreeSolution : public SolutionBase<Func> {
 public:
  long long kthLargestLevelSum(TreeNode* root, int k);

  KthLargestSumInABinaryTreeSolution();
};

}  // namespace problem_2583
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2583_H_
