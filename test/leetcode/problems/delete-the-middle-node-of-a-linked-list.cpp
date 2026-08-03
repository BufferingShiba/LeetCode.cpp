#include <gtest/gtest.h>

#include "leetcode/problems/delete-the-middle-node-of-a-linked-list.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2095 {

using testing::TestWithParam;
using testing::ValuesIn;

class DeleteTheMiddleNodeOfALinkedListTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DeleteTheMiddleNodeOfALinkedListSolution solution_;
};

TEST_P(DeleteTheMiddleNodeOfALinkedListTest, Example1) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 3, 4, 7, 1, 2, 6});
  leetcode::ListNode* res = solution_.deleteMiddle(head);
  EXPECT_EQ(leetcode::traverse(res), (std::vector<int>{1, 3, 4, 1, 2, 6}));
}

TEST_P(DeleteTheMiddleNodeOfALinkedListTest, Example2) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3, 4});
  leetcode::ListNode* res = solution_.deleteMiddle(head);
  EXPECT_EQ(leetcode::traverse(res), (std::vector<int>{1, 2, 4}));
}

TEST_P(DeleteTheMiddleNodeOfALinkedListTest, Example3) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{2, 1});
  leetcode::ListNode* res = solution_.deleteMiddle(head);
  EXPECT_EQ(leetcode::traverse(res), (std::vector<int>{2}));
}

TEST_P(DeleteTheMiddleNodeOfALinkedListTest, SelfAuthoredSingleNode) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{5});
  leetcode::ListNode* res = solution_.deleteMiddle(head);
  EXPECT_EQ(leetcode::traverse(res), (std::vector<int>{}));
}

TEST_P(DeleteTheMiddleNodeOfALinkedListTest, SelfAuthoredThreeNodes) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{1, 2, 3});
  leetcode::ListNode* res = solution_.deleteMiddle(head);
  EXPECT_EQ(leetcode::traverse(res), (std::vector<int>{1, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    DeleteTheMiddleNodeOfALinkedListTestSuite,
    DeleteTheMiddleNodeOfALinkedListTest,
    ValuesIn(DeleteTheMiddleNodeOfALinkedListSolution().getStrategyNames()));

}  // namespace problem_2095
}  // namespace leetcode
