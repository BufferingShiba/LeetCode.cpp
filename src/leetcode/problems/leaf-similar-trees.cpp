#include "leetcode/problems/leaf-similar-trees.h"

namespace leetcode {
namespace problem_872 {

static void collectLeaves(TreeNode* root, std::vector<int>& leaves) {
  if (!root) return;
  if (!root->left && !root->right) {
    leaves.push_back(root->val);
    return;
  }
  collectLeaves(root->left, leaves);
  collectLeaves(root->right, leaves);
}

static bool leafSimilarImpl(TreeNode* root1, TreeNode* root2) {
  std::vector<int> leaves1, leaves2;
  collectLeaves(root1, leaves1);
  collectLeaves(root2, leaves2);
  return leaves1 == leaves2;
}

LeafSimilarTreesSolution::LeafSimilarTreesSolution() {
  setMetaInfo({.id = 872, .title = "Leaf-Similar Trees",
               .url = "https://leetcode.com/problems/leaf-similar-trees/"});
  registerStrategy(
      {.name = "DFS",
       .expected = "Accepted",
       .time_complexity = "O(n1 + n2)",
       .space_complexity = "O(n1 + n2)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      leafSimilarImpl);
  setDefaultStrategy();
}

bool LeafSimilarTreesSolution::leafSimilar(TreeNode* root1, TreeNode* root2) {
  return getSolution()(root1, root2);
}

}  // namespace problem_872
}  // namespace leetcode
