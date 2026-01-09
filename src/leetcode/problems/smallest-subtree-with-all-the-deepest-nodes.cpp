#include "leetcode/problems/smallest-subtree-with-all-the-deepest-nodes.h"

namespace leetcode {
namespace problem_865 {

// 辅助结构体，存储节点信息和深度
struct NodeInfo {
  TreeNode* node;    // 包含所有最深节点的最小子树根节点
  int depth;         // 该子树的最大深度
  
  NodeInfo(TreeNode* n, int d) : node(n), depth(d) {}
};

// 递归函数：返回当前节点的信息
static NodeInfo dfs(TreeNode* root) {
  if (!root) {
    return NodeInfo(nullptr, 0);
  }
  
  NodeInfo left_info = dfs(root->left);
  NodeInfo right_info = dfs(root->right);
  
  // 如果左子树更深，返回左子树的结果
  if (left_info.depth > right_info.depth) {
    return NodeInfo(left_info.node, left_info.depth + 1);
  }
  
  // 如果右子树更深，返回右子树的结果
  if (right_info.depth > left_info.depth) {
    return NodeInfo(right_info.node, right_info.depth + 1);
  }
  
  // 左右子树深度相同，当前节点是最近公共祖先
  return NodeInfo(root, left_info.depth + 1);
}

// 一次遍历递归解法
// 时间复杂度: O(n)，每个节点访问一次
// 空间复杂度: O(h)，递归栈深度，最坏情况 O(n)
static TreeNode* solution1(TreeNode* root) {
  return dfs(root).node;
}

SmallestSubtreeWithAllTheDeepestNodesSolution::SmallestSubtreeWithAllTheDeepestNodesSolution() {
  setMetaInfo({.id = 865,
               .title = "Smallest Subtree with all the Deepest Nodes",
               .url = "https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/"});
  registerStrategy("Recursive One-Pass", solution1);
}

TreeNode* SmallestSubtreeWithAllTheDeepestNodesSolution::subtreeWithAllDeepest(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_865
}  // namespace leetcode