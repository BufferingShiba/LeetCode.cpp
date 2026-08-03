#include "leetcode/problems/binary-tree-cameras.h"

#include <algorithm>
#include <tuple>

namespace leetcode {
namespace problem_968 {

namespace {

constexpr int kInf = 10000;

// Returns {state0, state1, state2}:
//   state0: node not covered, needs parent to cover it
//   state1: node has a camera
//   state2: node has no camera, covered by at least one child
std::tuple<int, int, int> dfs(TreeNode* node) {
  if (!node) {
    // Null child: cannot hold a camera, doesn't need covering.
    return {0, kInf, 0};
  }

  auto [l0, l1, l2] = dfs(node->left);
  auto [r0, r1, r2] = dfs(node->right);

  // state0: children must be covered without this node's help.
  int state0 = std::min(l1, l2) + std::min(r1, r2);

  // state1: place a camera here; children are covered by this camera.
  int state1 = 1 + std::min({l0, l1, l2}) + std::min({r0, r1, r2});

  // state2: at least one child must have a camera to cover this node.
  int state2 = std::min(l1 + std::min(r1, r2), r1 + std::min(l1, l2));

  return {state0, state1, state2};
}

int minCameraCoverImpl(TreeNode* root) {
  auto [s0, s1, s2] = dfs(root);
  return std::min(s1, s2);
}

}  // namespace

BinaryTreeCamerasSolution::BinaryTreeCamerasSolution() {
  setMetaInfo({.id = 968,
               .title = "Binary Tree Cameras",
               .url = "https://leetcode.com/problems/binary-tree-cameras/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Dynamic Programming", "Tree", "Depth-First Search",
                "Binary Tree"}},
      minCameraCoverImpl);
}

int BinaryTreeCamerasSolution::minCameraCover(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_968
}  // namespace leetcode
