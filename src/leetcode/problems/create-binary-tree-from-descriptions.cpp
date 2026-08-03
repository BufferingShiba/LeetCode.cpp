#include "leetcode/problems/create-binary-tree-from-descriptions.h"

#include <unordered_map>
#include <unordered_set>

namespace leetcode {
namespace problem_2196 {

static TreeNode* solution1(vector<vector<int>>& descriptions) {
  std::unordered_map<int, TreeNode*> nodes;
  std::unordered_set<int> hasParent;

  for (const auto& desc : descriptions) {
    int parentVal = desc[0];
    int childVal = desc[1];
    bool isLeft = desc[2] == 1;

    TreeNode* parent = nullptr;
    auto pIt = nodes.find(parentVal);
    if (pIt == nodes.end()) {
      parent = new TreeNode(parentVal);
      nodes[parentVal] = parent;
    } else {
      parent = pIt->second;
    }

    TreeNode* child = nullptr;
    auto cIt = nodes.find(childVal);
    if (cIt == nodes.end()) {
      child = new TreeNode(childVal);
      nodes[childVal] = child;
    } else {
      child = cIt->second;
    }

    if (isLeft) {
      parent->left = child;
    } else {
      parent->right = child;
    }

    hasParent.insert(childVal);
  }

  // The root is the node that never appears as a child.
  for (const auto& entry : nodes) {
    if (hasParent.find(entry.first) == hasParent.end()) {
      return entry.second;
    }
  }

  return nullptr;
}

CreateBinaryTreeFromDescriptionsSolution::CreateBinaryTreeFromDescriptionsSolution() {
  setMetaInfo({
      .id = 2196,
      .title = "Create Binary Tree From Descriptions",
      .url = "https://leetcode.com/problems/create-binary-tree-from-descriptions"
  });
  registerStrategy({.name = "Hash Map Build", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Hash Table", "Tree", "Binary Tree"}}, solution1);
}

TreeNode* CreateBinaryTreeFromDescriptionsSolution::createBinaryTree(vector<vector<int>>& descriptions) {
  return getSolution()(descriptions);
}

}  // namespace problem_2196
}  // namespace leetcode
