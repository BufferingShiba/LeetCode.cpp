#ifndef LEETCODE_PROBLEMS_RANGE_SUM_OF_BST_H__
#define LEETCODE_PROBLEMS_RANGE_SUM_OF_BST_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_938 {

using Func = std::function<int(TreeNode*, int, int)>;

class RangeSumOfBstSolution : public SolutionBase<Func> {
 public:
  RangeSumOfBstSolution();

  int rangeSumBST(TreeNode* root, int low, int high);
};

}  // namespace problem_938
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RANGE_SUM_OF_BST_H__
