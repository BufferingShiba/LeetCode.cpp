#include "leetcode/problems/all-possible-full-binary-trees.h"

#include <unordered_map>

namespace leetcode::problem_894 {

namespace {

//! Deep-copy a tree so composed trees never share allocated nodes.
TreeNode* cloneTree(TreeNode* root) {
  if (root == nullptr) return nullptr;
  TreeNode* node = new TreeNode(root->val);
  node->left = cloneTree(root->left);
  node->right = cloneTree(root->right);
  return node;
}

}  // namespace

namespace {

struct AllPossibleFBTCache {
  std::unordered_map<int, std::vector<TreeNode*>> memo;

  std::vector<TreeNode*> build(int n) {
    auto it = memo.find(n);
    if (it != memo.end()) return it->second;

    std::vector<TreeNode*> result;
    if (n % 2 == 0) {
      // A full binary tree has an odd number of nodes.
      return memo[n] = result;
    }
    if (n == 1) {
      result.push_back(new TreeNode(0));
      return memo[n] = result;
    }

    // Root consumes one node; left subtree takes `left` nodes (must be odd),
    // right subtree takes the remaining n - 1 - left nodes.
    for (int left = 1; left <= n - 2; left += 2) {
      int right = n - 1 - left;
      std::vector<TreeNode*> leftTrees = build(left);
      std::vector<TreeNode*> rightTrees = build(right);
      for (TreeNode* l : leftTrees) {
        for (TreeNode* r : rightTrees) {
          TreeNode* root = new TreeNode(0);
          root->left = cloneTree(l);
          root->right = cloneTree(r);
          result.push_back(root);
        }
      }
    }
    return memo[n] = result;
  }
};

//! Public-interface free function. A fresh cache per top-level call guarantees
//! that no returned TreeNode is shared, so callers may safely delete them.
std::vector<TreeNode*> allPossibleFBTImpl(int n) {
  AllPossibleFBTCache cache;
  return cache.build(n);
}

}  // namespace

AllPossibleFullBinaryTreesSolution::AllPossibleFullBinaryTreesSolution() {
  setMetaInfo(
      {.id = 894,
       .title = "All Possible Full Binary Trees",
       .url =
           "https://leetcode.com/problems/all-possible-full-binary-trees/"});

  registerStrategy(
      {.name = "recursion_with_memo",
       .expected = "Accepted",
       .time_complexity = "O(Catalan(n / 2))",
       .space_complexity = "O(Catalan(n / 2))",
       .tags = {"Dynamic Programming", "Tree", "Recursion", "Memoization"},
       .notes =
           "Split remaining nodes into odd-sized left/right subtrees; memoize "
           "shapes and deep-copy when composing to keep returned trees unshared."},
      allPossibleFBTImpl);
}

std::vector<TreeNode*> AllPossibleFullBinaryTreesSolution::allPossibleFBT(
    int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_894
