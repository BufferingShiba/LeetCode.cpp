#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/insertion-sort-list.h"

namespace leetcode {
namespace problem_147 {

class InsertionSortListTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  InsertionSortListSolution solution_;
};

TEST_P(InsertionSortListTest, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{4, 2, 1, 3});
  ListNode* result = solution_.insertionSortList(head);
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(InsertionSortListTest, Example2) {
  ListNode* head = constructLinkedList(std::vector<int>{-1, 5, 3, 4, 0});
  ListNode* result = solution_.insertionSortList(head);
  std::vector<int> expected = {-1, 0, 3, 4, 5};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(InsertionSortListTest, SelfAuthoredSingleNode) {
  ListNode* head = constructLinkedList(std::vector<int>{42});
  ListNode* result = solution_.insertionSortList(head);
  std::vector<int> expected = {42};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(InsertionSortListTest, SelfAuthoredAlreadySorted) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* result = solution_.insertionSortList(head);
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(InsertionSortListTest, SelfAuthoredReverseSorted) {
  ListNode* head = constructLinkedList(std::vector<int>{5, 4, 3, 2, 1});
  ListNode* result = solution_.insertionSortList(head);
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(traverse(result), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    InsertionSortListTest,
    ::testing::ValuesIn(InsertionSortListSolution().getStrategyNames()));

}  // namespace problem_147
}  // namespace leetcode
