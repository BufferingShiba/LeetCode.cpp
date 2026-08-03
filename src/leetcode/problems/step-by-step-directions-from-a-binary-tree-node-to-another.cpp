#include "leetcode/problems/step-by-step-directions-from-a-binary-tree-node-to-another.h"

#include <string>

namespace leetcode::problem_2096 {
namespace {

bool dfs(TreeNode* node, int target, std::string& path) {
  if (node == nullptr) return false;
  if (node->val == target) return true;
  if (node->left != nullptr) {
    path.push_back('L');
    if (dfs(node->left, target, path)) return true;
    path.pop_back();
  }
  if (node->right != nullptr) {
    path.push_back('R');
    if (dfs(node->right, target, path)) return true;
    path.pop_back();
  }
  return false;
}

std::string getDirectionsImpl(TreeNode* root, int startValue, int destValue) {
  std::string rootToStart;
  std::string rootToDest;
  dfs(root, startValue, rootToStart);
  dfs(root, destValue, rootToDest);

  // Find the length of the common prefix (path up to the LCA).
  size_t commonLen = 0;
  while (commonLen < rootToStart.size() && commonLen < rootToDest.size() &&
         rootToStart[commonLen] == rootToDest[commonLen]) {
    ++commonLen;
  }

  std::string result;
  // From start up to LCA: all 'U'.
  result.append(rootToStart.size() - commonLen, 'U');
  // From LCA down to dest.
  result.append(rootToDest.substr(commonLen));
  return result;
}

}  // namespace

StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution::
    StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution() {
  setMetaInfo({.id = 2096,
               .title = "Step-By-Step Directions From a Binary Tree Node to Another",
               .url =
                   "https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/"});
  registerStrategy(
      {.name = "LCA path via root paths",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"},
       .notes =
           "Find root-to-start and root-to-dest paths via DFS, drop the common "
           "prefix (up to LCA), turn start part into 'U's and append dest part."},
      getDirectionsImpl);
}

std::string StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution::getDirections(
    TreeNode* root, int startValue, int destValue) {
  return getSolution()(root, startValue, destValue);
}

}  // namespace leetcode::problem_2096
