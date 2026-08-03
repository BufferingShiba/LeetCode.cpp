#include <gtest/gtest.h>
#include "leetcode/problems/reverse-linked-list-ii.h"

using namespace leetcode;

namespace {

class ReverseLinkedListIiTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  problem_92::ReverseLinkedListIiSolution solution_;
};

TEST_P(ReverseLinkedListIiTest, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution_.reverseBetween(head, 2, 4);
  EXPECT_EQ(traverse(result), std::vector<int>({1, 4, 3, 2, 5}));
}

TEST_P(ReverseLinkedListIiTest, Example2) {
  ListNode* head = constructLinkedList(std::vector<int>{5});
  ListNode* result = solution_.reverseBetween(head, 1, 1);
  EXPECT_EQ(traverse(result), std::vector<int>({5}));
}

TEST_P(ReverseLinkedListIiTest, SelfAuthoredReverseFullList) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution_.reverseBetween(head, 1, 5);
  EXPECT_EQ(traverse(result), std::vector<int>({5, 4, 3, 2, 1}));
}

TEST_P(ReverseLinkedListIiTest, SelfAuthoredReverseFirstTwo) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution_.reverseBetween(head, 1, 2);
  EXPECT_EQ(traverse(result), std::vector<int>({2, 1, 3, 4, 5}));
}

TEST_P(ReverseLinkedListIiTest, SelfAuthoredReverseLastTwo) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution_.reverseBetween(head, 4, 5);
  EXPECT_EQ(traverse(result), std::vector<int>({1, 2, 3, 5, 4}));
}

TEST_P(ReverseLinkedListIiTest, SelfAuthoredSingleElementRange) {
  ListNode* head = constructLinkedList(std::vector<int>{3, 7, 2});
  ListNode* result = solution_.reverseBetween(head, 2, 2);
  EXPECT_EQ(traverse(result), std::vector<int>({3, 7, 2}));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseLinkedListIi,
    ReverseLinkedListIiTest,
    testing::ValuesIn(problem_92::ReverseLinkedListIiSolution().getStrategyNames()));

}  // namespace
