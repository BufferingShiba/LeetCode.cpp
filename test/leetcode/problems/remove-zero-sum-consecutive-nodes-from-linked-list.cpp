#include "leetcode/problems/remove-zero-sum-consecutive-nodes-from-linked-list.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1171 {

class RemoveZeroSumConsecutiveNodesFromLinkedListTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveZeroSumConsecutiveNodesFromLinkedListSolution solution;
};

TEST_P(RemoveZeroSumConsecutiveNodesFromLinkedListTest, Example1) {
  ListNode* input = leetcode::constructLinkedList(std::vector<int>{1, 2, -3, 3, 1});
  ListNode* result = solution.removeZeroSumSublists(input);
  EXPECT_EQ((std::vector<int>{3, 1}), leetcode::traverse(result));
}

TEST_P(RemoveZeroSumConsecutiveNodesFromLinkedListTest, Example2) {
  ListNode* input = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, -3, 4});
  ListNode* result = solution.removeZeroSumSublists(input);
  EXPECT_EQ((std::vector<int>{1, 2, 4}), leetcode::traverse(result));
}

TEST_P(RemoveZeroSumConsecutiveNodesFromLinkedListTest, Example3) {
  ListNode* input = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, -3, -2});
  ListNode* result = solution.removeZeroSumSublists(input);
  EXPECT_EQ((std::vector<int>{1}), leetcode::traverse(result));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, RemoveZeroSumConsecutiveNodesFromLinkedListTest,
    ::testing::ValuesIn(RemoveZeroSumConsecutiveNodesFromLinkedListSolution().getStrategyNames()));

}  // namespace problem_1171
}  // namespace leetcode
