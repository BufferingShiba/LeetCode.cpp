#include <gtest/gtest.h>

#include <optional>
#include <queue>
#include <vector>

#include "leetcode/problems/maximum-depth-of-n-ary-tree.h"

namespace leetcode {
namespace problem_559 {

// Helper: construct an N-ary tree from level-order serialization.
// The format: root, null, children_of_root, null, children_of_first_child, ...
static Node* constructNaryTree(const std::vector<std::optional<int>>& values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }
  Node* root = new Node(values[0].value());
  std::queue<Node*> q;
  q.push(root);

  size_t i = 1;
  while (!q.empty() && i < values.size()) {
    Node* current = q.front();
    q.pop();

    // Skip the null separator before this node's children group.
    if (i < values.size() && !values[i].has_value()) {
      ++i;
    }

    // Read all children until next null or end of array.
    while (i < values.size() && values[i].has_value()) {
      Node* child = new Node(values[i].value());
      current->children.push_back(child);
      q.push(child);
      ++i;
    }
  }
  return root;
}

class MaximumDepthOfNAryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumDepthOfNAryTreeSolution solution;
};

TEST_P(MaximumDepthOfNAryTreeTest, Example1) {
  Node* root =
      constructNaryTree(std::vector<std::optional<int>>{1, std::nullopt, 3, 2, 4,
                                                         std::nullopt, 5, 6});
  EXPECT_EQ(solution.maxDepth(root), 3);
}

TEST_P(MaximumDepthOfNAryTreeTest, Example2) {
  Node* root = constructNaryTree(
      std::vector<std::optional<int>>{1,   std::nullopt, 2,   3,   4,
                                      5,   std::nullopt, std::nullopt, 6,
                                      7,   std::nullopt, 8,   std::nullopt,
                                      9,   10,          std::nullopt, std::nullopt,
                                      11,  std::nullopt, 12,  std::nullopt,
                                      13,  std::nullopt, std::nullopt, 14});
  EXPECT_EQ(solution.maxDepth(root), 5);
}

TEST_P(MaximumDepthOfNAryTreeTest, SelfAuthoredEmptyTree) {
  EXPECT_EQ(solution.maxDepth(nullptr), 0);
}

TEST_P(MaximumDepthOfNAryTreeTest, SelfAuthoredSingleNode) {
  Node* root = constructNaryTree(std::vector<std::optional<int>>{1});
  EXPECT_EQ(solution.maxDepth(root), 1);
}

TEST_P(MaximumDepthOfNAryTreeTest, SelfAuthoredLinearTree) {
  // 1 -> 2 -> 3  (each node has exactly one child)
  Node* root = constructNaryTree(
      std::vector<std::optional<int>>{1, std::nullopt, 2, std::nullopt, 3});
  EXPECT_EQ(solution.maxDepth(root), 3);
}

INSTANTIATE_TEST_SUITE_P(Strategies, MaximumDepthOfNAryTreeTest,
                         ::testing::ValuesIn(
                             MaximumDepthOfNAryTreeSolution().getStrategyNames()));

}  // namespace problem_559
}  // namespace leetcode
