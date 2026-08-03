#ifndef LEETCODE_PROBLEMS_EVEN_ODD_TREE_H_
#define LEETCODE_PROBLEMS_EVEN_ODD_TREE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1609 {

using Func = std::function<bool(TreeNode*)>;

class EvenOddTreeSolution : public SolutionBase<Func> {
 public:
  EvenOddTreeSolution();

  bool isEvenOddTree(TreeNode* root);
};

}  // namespace problem_1609
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EVEN_ODD_TREE_H_
