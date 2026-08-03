#include <gtest/gtest.h>

#include "leetcode/problems/populating-next-right-pointers-in-each-node-ii.h"

#include <queue>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_117 {

namespace {

using leetcode::problem_117::Node;

// Build a Node tree from level-order values. value -1 means null.
Node* buildNodeTree(const std::vector<int>& values) {
  if (values.empty() || values[0] == -1) {
    return nullptr;
  }
  Node* root = new Node(values[0]);
  std::queue<Node*> q;
  q.push(root);
  int i = 1;
  while (i < static_cast<int>(values.size())) {
    Node* node = q.front();
    q.pop();
    if (values[i] != -1) {
      node->left = new Node(values[i]);
      q.push(node->left);
    }
    i++;
    if (i < static_cast<int>(values.size()) && values[i] != -1) {
      node->right = new Node(values[i]);
      q.push(node->right);
    }
    i++;
  }
  return root;
}

void deleteNodeTree(Node* root) {
  if (root == nullptr) return;
  deleteNodeTree(root->left);
  deleteNodeTree(root->right);
  delete root;
}

// Serialize the connected tree level by level (each level terminated by #).
std::vector<int> serializeNext(Node* root) {
  std::vector<int> result;
  Node* cur = root;
  while (cur != nullptr) {
    Node* levelStart = cur;
    for (Node* p = levelStart; p != nullptr; p = p->next) {
      result.push_back(p->val);
    }
    result.push_back(-101);  // level delimiter
    while (levelStart != nullptr && levelStart->left == nullptr &&
           levelStart->right == nullptr) {
      levelStart = levelStart->next;
    }
    if (levelStart == nullptr) break;
    cur = levelStart->left != nullptr ? levelStart->left : levelStart->right;
  }
  return result;
}

}  // namespace

class PopulatingNextRightPointersInEachNodeIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PopulatingNextRightPointersInEachNodeIiSolution solution;
};

TEST_P(PopulatingNextRightPointersInEachNodeIiTest, Example1) {
  Node* root = buildNodeTree({1, 2, 3, 4, 5, -1, 7});
  Node* connected = solution.connect(root);
  std::vector<int> expected = {1, -101, 2, 3, -101, 4, 5, 7, -101};
  EXPECT_EQ(serializeNext(connected), expected);
  deleteNodeTree(root);
}

TEST_P(PopulatingNextRightPointersInEachNodeIiTest, EmptyTree) {
  Node* root = nullptr;
  Node* connected = solution.connect(root);
  EXPECT_EQ(connected, nullptr);
}

TEST_P(PopulatingNextRightPointersInEachNodeIiTest, SelfAuthoredSingleNode) {
  Node* root = buildNodeTree({1});
  Node* connected = solution.connect(root);
  std::vector<int> expected = {1, -101};
  EXPECT_EQ(serializeNext(connected), expected);
  deleteNodeTree(root);
}

TEST_P(PopulatingNextRightPointersInEachNodeIiTest, SelfAuthoredSkewedLeftTree) {
  // A tree with only left children: 1 -> 2 -> 3
  Node* root = buildNodeTree({1, 2, -1, 3, -1, -1, -1});
  Node* connected = solution.connect(root);
  std::vector<int> expected = {1, -101, 2, -101, 3, -101};
  EXPECT_EQ(serializeNext(connected), expected);
  deleteNodeTree(root);
}

INSTANTIATE_TEST_SUITE_P(
    PopulatingNextRightPointersInEachNodeIiTests,
    PopulatingNextRightPointersInEachNodeIiTest,
    ::testing::ValuesIn(
        PopulatingNextRightPointersInEachNodeIiSolution().getStrategyNames()));

}  // namespace problem_117
}  // namespace leetcode
