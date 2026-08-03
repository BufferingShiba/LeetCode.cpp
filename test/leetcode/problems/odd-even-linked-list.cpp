#include "leetcode/problems/odd-even-linked-list.h"
#include <gtest/gtest.h>
#include <vector>

namespace leetcode {
namespace problem_328 {
namespace {

leetcode::ListNode* build(const std::vector<int>& vals) {
  return leetcode::constructLinkedList(vals);
}

std::vector<int> toVector(leetcode::ListNode* head) {
  return leetcode::traverse(head);
}

}  // namespace

class OddEvenLinkedListTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  OddEvenLinkedListSolution solution_;
};

TEST_P(OddEvenLinkedListTest, Example1) {
  leetcode::ListNode* head = build({1, 2, 3, 4, 5});
  leetcode::ListNode* result = solution_.oddEvenList(head);
  EXPECT_EQ(toVector(result), std::vector<int>({1, 3, 5, 2, 4}));
}

TEST_P(OddEvenLinkedListTest, Example2) {
  leetcode::ListNode* head = build({2, 1, 3, 5, 6, 4, 7});
  leetcode::ListNode* result = solution_.oddEvenList(head);
  EXPECT_EQ(toVector(result), std::vector<int>({2, 3, 6, 7, 1, 5, 4}));
}

TEST_P(OddEvenLinkedListTest, SelfAuthoredEmptyList) {
  leetcode::ListNode* result = solution_.oddEvenList(nullptr);
  EXPECT_EQ(result, nullptr);
}

TEST_P(OddEvenLinkedListTest, SelfAuthoredSingleNode) {
  leetcode::ListNode* head = build({10});
  leetcode::ListNode* result = solution_.oddEvenList(head);
  EXPECT_EQ(toVector(result), std::vector<int>({10}));
}

TEST_P(OddEvenLinkedListTest, SelfAuthoredTwoNodes) {
  leetcode::ListNode* head = build({1, 2});
  leetcode::ListNode* result = solution_.oddEvenList(head);
  EXPECT_EQ(toVector(result), std::vector<int>({1, 2}));
}

TEST_P(OddEvenLinkedListTest, SelfAuthoredOddCountEvenLength) {
  leetcode::ListNode* head = build({1, 2, 3, 4});
  leetcode::ListNode* result = solution_.oddEvenList(head);
  EXPECT_EQ(toVector(result), std::vector<int>({1, 3, 2, 4}));
}

INSTANTIATE_TEST_SUITE_P(
    OddEvenLinkedListTestSuite, OddEvenLinkedListTest,
    ::testing::ValuesIn(OddEvenLinkedListSolution().getStrategyNames()));

}  // namespace problem_328
}  // namespace leetcode
