// LeetCode 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

#ifndef LEETCODE_PROBLEMS_FIND_MODE_IN_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_FIND_MODE_IN_BINARY_SEARCH_TREE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_501 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class FindModeInBinarySearchTreeSolution
    : public SolutionBase<Func> {
 public:
  FindModeInBinarySearchTreeSolution();

  std::vector<int> findMode(TreeNode* root);
};

}  // namespace leetcode::problem_501

#endif  // LEETCODE_PROBLEMS_FIND_MODE_IN_BINARY_SEARCH_TREE_H__
