#include "leetcode/problems/path-in-zigzag-labelled-binary-tree.h"

#include <algorithm>
#include <cmath>

namespace leetcode::problem_1104 {

namespace {

std::vector<int> pathInZigZagTreeImpl(int label) {
  // Determine the level of the given label (1-indexed)
  int level = static_cast<int>(std::log2(label)) + 1;

  std::vector<int> path;

  while (label >= 1) {
    path.push_back(label);

    // Range of current level: [lo, hi]
    int lo = 1 << (level - 1);
    int hi = (1 << level) - 1;

    int normal;
    if (level % 2 == 0) {
      // Even level: label is right-to-left, mirror it to normal left-to-right
      normal = lo + hi - label;
    } else {
      normal = label;
    }

    // Parent in a normal complete binary tree
    int parent_normal = normal / 2;

    // Move up one level
    --level;
    if (level == 0) break;  // parent of root, done

    lo = 1 << (level - 1);
    hi = (1 << level) - 1;

    if (level % 2 == 0) {
      // Parent level is even, mirror back to zigzag
      label = lo + hi - parent_normal;
    } else {
      label = parent_normal;
    }
  }

  std::reverse(path.begin(), path.end());
  return path;
}

}  // namespace

PathInZigzagLabelledBinaryTreeSolution::PathInZigzagLabelledBinaryTreeSolution() {
  setMetaInfo({.id = 1104,
               .title = "Path In Zigzag Labelled Binary Tree",
               .url = "https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/"});

  registerStrategy({.name = "Math mirror",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Math", "Tree", "Binary Tree"}},
                   pathInZigZagTreeImpl);
}

std::vector<int> PathInZigzagLabelledBinaryTreeSolution::pathInZigZagTree(int label) {
  return getSolution()(label);
}

}  // namespace leetcode::problem_1104
