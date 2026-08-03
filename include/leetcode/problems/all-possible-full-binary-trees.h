#ifndef LEETCODE_PROBLEMS_ALL_POSSIBLE_FULL_BINARY_TREES_H__
#define LEETCODE_PROBLEMS_ALL_POSSIBLE_FULL_BINARY_TREES_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_894 {

using Func = std::function<std::vector<TreeNode*>(int)>;

class AllPossibleFullBinaryTreesSolution
    : public SolutionBase<Func> {
 public:
  AllPossibleFullBinaryTreesSolution();

  std::vector<TreeNode*> allPossibleFBT(int n);
};

}  // namespace leetcode::problem_894

#endif  // LEETCODE_PROBLEMS_ALL_POSSIBLE_FULL_BINARY_TREES_H__
