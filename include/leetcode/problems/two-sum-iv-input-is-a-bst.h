#ifndef LEETCODE_PROBLEMS_TWO_SUM_IV_INPUT_IS_A_BST_H_
#define LEETCODE_PROBLEMS_TWO_SUM_IV_INPUT_IS_A_BST_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_653 {

using Func = std::function<bool(TreeNode*, int)>;

class TwoSumIvInputIsABstSolution
    : public SolutionBase<Func> {
 public:
  TwoSumIvInputIsABstSolution();

  bool findTarget(TreeNode* root, int k);
};

}  // namespace problem_653
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TWO_SUM_IV_INPUT_IS_A_BST_H_
