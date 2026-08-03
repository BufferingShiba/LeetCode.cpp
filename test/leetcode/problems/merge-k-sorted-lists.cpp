#include <gtest/gtest.h>

#include "leetcode/problems/merge-k-sorted-lists.h"

using namespace leetcode;
using namespace leetcode::problem_23;

class MergeKSortedListsTest : public testing::TestWithParam<std::string> {
 protected:
  MergeKSortedListsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MergeKSortedListsTest, Example1) {
  std::vector<ListNode*> lists = {
      constructLinkedList(std::vector<int>{1, 4, 5}),
      constructLinkedList(std::vector<int>{1, 3, 4}),
      constructLinkedList(std::vector<int>{2, 6})};
  ListNode* result = solution.mergeKLists(lists);
  std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
  EXPECT_EQ(traverse(result), expected);
}

TEST_P(MergeKSortedListsTest, Example2) {
  std::vector<ListNode*> lists;
  ListNode* result = solution.mergeKLists(lists);
  EXPECT_EQ(result, nullptr);
}

TEST_P(MergeKSortedListsTest, Example3) {
  std::vector<ListNode*> lists = {nullptr};
  ListNode* result = solution.mergeKLists(lists);
  EXPECT_EQ(result, nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MergeKSortedListsTest,
    testing::ValuesIn(MergeKSortedListsSolution().getStrategyNames()));
