#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1339 {

using Func = std::function<int(TreeNode* root)>;

class MaximumProductOfSplittedBinaryTreeSolution
    : public SolutionBase<Func> {
 public:
  int maxProduct(TreeNode* root);

  MaximumProductOfSplittedBinaryTreeSolution();
};

}  // namespace problem_1339
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H__
