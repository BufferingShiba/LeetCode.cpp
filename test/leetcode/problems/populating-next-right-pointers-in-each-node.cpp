#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/populating-next-right-pointers-in-each-node.h"

namespace leetcode {
namespace problem_116 {
namespace {

// Build a perfect binary tree from a level-order vector.
Node* buildTree(const std::vector<int>& values) {
  if (values.empty()) {
    return nullptr;
  }
  std::vector<Node*> nodes;
  nodes.reserve(values.size());
  for (int v : values) {
    nodes.push_back(new Node(v));
  }
  for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
    if (2 * i + 1 < static_cast<int>(nodes.size())) {
      nodes[i]->left = nodes[2 * i + 1];
    }
    if (2 * i + 2 < static_cast<int>(nodes.size())) {
      nodes[i]->right = nodes[2 * i + 2];
    }
  }
  return nodes.empty() ? nullptr : nodes[0];
}

// Serialize next pointers level by level with '#' separating levels.
std::vector<int> serializeLevels(Node* root) {
  std::vector<int> result;
  Node* level_start = root;
  while (level_start != nullptr) {
    Node* curr = level_start;
    while (curr != nullptr) {
      result.push_back(curr->val);
      curr = curr->next;
    }
    result.push_back(-1);  // mark end of level
    level_start = level_start->left;
  }
  return result;
}

// Free all nodes; next pointers create cross links so delete each node once only.
void deleteTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  Node* row = root;
  while (row != nullptr) {
    Node* curr = row;
    Node* next_row = row->left;
    while (curr != nullptr) {
      Node* nxt = curr->next;
      delete curr;
      curr = nxt;
    }
    row = next_row;
  }
}

class PopulatingNextRightPointersInEachNodeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  PopulatingNextRightPointersInEachNodeSolution solution;
};

TEST_P(PopulatingNextRightPointersInEachNodeTest, Example1) {
  Node* root = buildTree({1, 2, 3, 4, 5, 6, 7});
  Node* out = solution.getSolution()(root);
  EXPECT_EQ(out, root);
  EXPECT_EQ(serializeLevels(out), std::vector<int>({1, -1, 2, 3, -1, 4, 5, 6, 7, -1}));
  deleteTree(out);
}

TEST_P(PopulatingNextRightPointersInEachNodeTest, EmptyTree) {
  Node* root = buildTree({});
  Node* out = solution.getSolution()(root);
  EXPECT_EQ(out, nullptr);
}

TEST_P(PopulatingNextRightPointersInEachNodeTest, SelfAuthoredSingleNode) {
  Node* root = buildTree({1});
  Node* out = solution.getSolution()(root);
  EXPECT_EQ(out, root);
  EXPECT_EQ(serializeLevels(out), std::vector<int>({1, -1}));
  deleteTree(out);
}

TEST_P(PopulatingNextRightPointersInEachNodeTest, SelfAuthoredTwoLevelTree) {
  Node* root = buildTree({1, 2, 3});
  Node* out = solution.getSolution()(root);
  EXPECT_EQ(serializeLevels(out), std::vector<int>({1, -1, 2, 3, -1}));
  deleteTree(out);
}

INSTANTIATE_TEST_SUITE_P(
    PopulatingNextRightPointersInEachNodeTestSuite,
    PopulatingNextRightPointersInEachNodeTest,
    ::testing::ValuesIn(
        PopulatingNextRightPointersInEachNodeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_116
}  // namespace leetcode
