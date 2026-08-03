#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/middle-of-the-linked-list.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode::problem_876 {

class MiddleOfTheLinkedListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MiddleOfTheLinkedListSolution solution_;
};

TEST_P(MiddleOfTheLinkedListTest, Example1_OddLength) {
  leetcode::ListNode* head = leetcode::constructLinkedList({1, 2, 3, 4, 5});
  leetcode::ListNode* result = solution_.middleNode(head);
  EXPECT_EQ(leetcode::traverse(result), std::vector<int>({3, 4, 5}));
}

TEST_P(MiddleOfTheLinkedListTest, Example2_EvenLength) {
  leetcode::ListNode* head = leetcode::constructLinkedList({1, 2, 3, 4, 5, 6});
  leetcode::ListNode* result = solution_.middleNode(head);
  EXPECT_EQ(leetcode::traverse(result), std::vector<int>({4, 5, 6}));
}

TEST_P(MiddleOfTheLinkedListTest, SelfAuthoredSingleNode) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{7});
  leetcode::ListNode* result = solution_.middleNode(head);
  EXPECT_EQ(leetcode::traverse(result), std::vector<int>({7}));
}

INSTANTIATE_TEST_SUITE_P(
    MiddleOfTheLinkedListTests, MiddleOfTheLinkedListTest,
    ::testing::ValuesIn(MiddleOfTheLinkedListSolution().getStrategyNames()));

}  // namespace leetcode::problem_876
