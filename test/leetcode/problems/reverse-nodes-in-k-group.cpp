#include "leetcode/problems/reverse-nodes-in-k-group.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_25 {

class ReverseNodesInKGroupTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ReverseNodesInKGroupSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(ReverseNodesInKGroupTest, Example1) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  leetcode::ListNode* result = solution.reverseKGroup(head, 2);
  std::vector<int> expected = {2, 1, 4, 3, 5};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

TEST_P(ReverseNodesInKGroupTest, Example2) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  leetcode::ListNode* result = solution.reverseKGroup(head, 3);
  std::vector<int> expected = {3, 2, 1, 4, 5};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

TEST_P(ReverseNodesInKGroupTest, SelfAuthoredSingleGroup) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3});
  leetcode::ListNode* result = solution.reverseKGroup(head, 3);
  std::vector<int> expected = {3, 2, 1};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

TEST_P(ReverseNodesInKGroupTest, SelfAuthoredKEqualsOne) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4});
  leetcode::ListNode* result = solution.reverseKGroup(head, 1);
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

TEST_P(ReverseNodesInKGroupTest, SelfAuthoredExactMultiple) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4});
  leetcode::ListNode* result = solution.reverseKGroup(head, 2);
  std::vector<int> expected = {2, 1, 4, 3};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

TEST_P(ReverseNodesInKGroupTest, SelfAuthoredLeftoverNodes) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4, 5, 6, 7});
  leetcode::ListNode* result = solution.reverseKGroup(head, 3);
  std::vector<int> expected = {3, 2, 1, 6, 5, 4, 7};
  EXPECT_EQ(leetcode::traverse(result), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ReverseNodesInKGroupTestSuite,
    ReverseNodesInKGroupTest,
    ::testing::ValuesIn(ReverseNodesInKGroupSolution().getStrategyNames()));

}  // namespace problem_25
}  // namespace leetcode
