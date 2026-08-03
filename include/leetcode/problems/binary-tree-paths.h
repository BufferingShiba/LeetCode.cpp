#ifndef LEETCODE_PROBLEMS_BINARY_TREE_PATHS_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_PATHS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_257 {

using Func = std::function<std::vector<std::string>(TreeNode*)>;

class BinaryTreePathsSolution : public SolutionBase<Func> {
 public:
  BinaryTreePathsSolution();

  std::vector<std::string> binaryTreePaths(TreeNode* root);
};

}  // namespace leetcode::problem_257

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_PATHS_H__
