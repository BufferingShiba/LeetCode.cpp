#ifndef LEETCODE_PROBLEMS_RECOVER_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_RECOVER_BINARY_SEARCH_TREE_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_99 {

using Func = std::function<void(leetcode::TreeNode*)>;

class RecoverBinarySearchTreeSolution
    : public SolutionBase<Func> {
 public:
  RecoverBinarySearchTreeSolution() {
    setMetaInfo({.id = 99,
                 .title = "Recover Binary Search Tree",
                 .url = "https://leetcode.com/problems/recover-binary-search-tree/"});
    registerStrategy({.name = "InorderRecursive",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(H)",
                      .tags = {"Tree", "DFS", "Binary Search Tree"}},
                     recoverTreeInorder);
    registerStrategy({.name = "MorrisTraversal",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Tree", "Binary Search Tree", "Morris"}},
                     recoverTreeMorris);
  }

  // Public interface matching the LeetCode problem method.
  void recoverTree(TreeNode* root) { return getSolution()(root); }

  // Registered strategy entry points (defined in source).
  static void recoverTreeInorder(TreeNode* root);
  static void recoverTreeMorris(TreeNode* root);
};

}  // namespace problem_99
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RECOVER_BINARY_SEARCH_TREE_H__
