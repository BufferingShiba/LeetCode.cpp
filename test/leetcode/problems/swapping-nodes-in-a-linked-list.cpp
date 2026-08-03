#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/swapping-nodes-in-a-linked-list.h"

namespace leetcode {
namespace problem_1721 {
namespace {

class SwappingNodesInALinkedListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SwappingNodesInALinkedListSolution solution;
};

TEST_P(SwappingNodesInALinkedListTest, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution.swapNodes(head, 2);
  std::vector<int> expected = {1, 4, 3, 2, 5};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(SwappingNodesInALinkedListTest, Example2) {
  ListNode* head =
      constructLinkedList(std::vector<int>{7, 9, 6, 6, 7, 8, 3, 0, 9, 5});
  ListNode* result = solution.swapNodes(head, 5);
  std::vector<int> expected = {7, 9, 6, 6, 8, 7, 3, 0, 9, 5};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(SwappingNodesInALinkedListTest, SelfAuthoredSwapSameNode) {
  // k is exactly the middle, both k-th nodes point to the same node.
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution.swapNodes(head, 3);
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(SwappingNodesInALinkedListTest, SelfAuthoredSingleNode) {
  ListNode* head = constructLinkedList(std::vector<int>{42});
  ListNode* result = solution.swapNodes(head, 1);
  std::vector<int> expected = {42};
  EXPECT_EQ(traverse(result), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SwappingNodesInALinkedListTestSuite, SwappingNodesInALinkedListTest,
    ::testing::ValuesIn(
        SwappingNodesInALinkedListSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1721
}  // namespace leetcode
