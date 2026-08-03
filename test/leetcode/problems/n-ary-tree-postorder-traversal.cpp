#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/n-ary-tree-postorder-traversal.h"

namespace leetcode {
namespace problem_590 {

namespace {

// Build n-ary tree from BFS serialization. Value -1 represents the null
// separator that terminates a node's children list.
Node* buildNAryTree(const std::vector<int>& values) {
  if (values.empty()) {
    return nullptr;
  }
  Node* root = new Node(values[0]);
  std::vector<Node*> queue;
  queue.push_back(root);
  std::size_t i = 1;
  while (i < values.size() && !queue.empty()) {
    Node* parent = queue.front();
    queue.erase(queue.begin());
    ++i;  // skip the null before the children list
    while (i < values.size() && values[i] != -1) {
      Node* child = new Node(values[i]);
      parent->children.push_back(child);
      queue.push_back(child);
      ++i;
    }
  }
  return root;
}

void freeNAryTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  for (Node* child : root->children) {
    freeNAryTree(child);
  }
  delete root;
}

}  // namespace

class NAryTreePostorderTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NAryTreePostorderTraversalSolution solution;
};

TEST_P(NAryTreePostorderTraversalTest, Example1) {
  Node* root =
      buildNAryTree({1, -1, 3, 2, 4, -1, 5, 6});
  std::vector<int> expected = {5, 6, 3, 2, 4, 1};
  EXPECT_EQ(solution.postorder(root), expected);
  freeNAryTree(root);
}

TEST_P(NAryTreePostorderTraversalTest, Example2) {
  Node* root = buildNAryTree({1, -1, 2, 3, 4, 5, -1, -1, 6, 7, -1, 8, -1,
                              9, 10, -1, -1, 11, -1, 12, -1, 13, -1, -1, 14});
  std::vector<int> expected = {2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
  EXPECT_EQ(solution.postorder(root), expected);
  freeNAryTree(root);
}

TEST_P(NAryTreePostorderTraversalTest, SelfAuthoredEmptyTree) {
  Node* root = nullptr;
  std::vector<int> expected;
  EXPECT_EQ(solution.postorder(root), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NAryTreePostorderTraversalTest,
    ::testing::ValuesIn(NAryTreePostorderTraversalSolution().getStrategyNames()));

}  // namespace problem_590
}  // namespace leetcode
