#include "leetcode/problems/binary-tree-paths.h"

#include <string>
#include <vector>

namespace leetcode::problem_257 {

namespace {

void dfs(TreeNode* node, std::string path, std::vector<std::string>& result) {
  if (path.empty()) {
    path = std::to_string(node->val);
  } else {
    path += "->" + std::to_string(node->val);
  }
  if (node->left == nullptr && node->right == nullptr) {
    result.push_back(path);
    return;
  }
  if (node->left != nullptr) {
    dfs(node->left, path, result);
  }
  if (node->right != nullptr) {
    dfs(node->right, path, result);
  }
}

std::vector<std::string> binaryTreePathsImpl(TreeNode* root) {
  std::vector<std::string> result;
  dfs(root, "", result);
  return result;
}

}  // namespace

BinaryTreePathsSolution::BinaryTreePathsSolution() {
  this->setMetaInfo({.id = 257,
                     .title = "Binary Tree Paths",
                     .url = "https://leetcode.com/problems/binary-tree-paths/"});
  this->registerStrategy(
      {.name = "dfs",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Depth-First Search", "String", "Backtracking",
                "Binary Tree"}},
      binaryTreePathsImpl);
}

std::vector<std::string> BinaryTreePathsSolution::binaryTreePaths(
    TreeNode* root) {
  return this->getSolution()(root);
}

}  // namespace leetcode::problem_257
