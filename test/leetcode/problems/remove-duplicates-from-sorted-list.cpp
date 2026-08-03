#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/remove-duplicates-from-sorted-list.h"

namespace leetcode {
namespace problem_83 {

class RemoveDuplicatesFromSortedListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveDuplicatesFromSortedListSolution solution;
};

TEST_P(RemoveDuplicatesFromSortedListTest, Example1) {
  leetcode::ListNode* head =
      leetcode::constructLinkedList(std::vector<int>{1, 1, 2});
  leetcode::ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> actual = leetcode::traverse(result);
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(expected, actual);
}

TEST_P(RemoveDuplicatesFromSortedListTest, Example2) {
  leetcode::ListNode* head =
      leetcode::constructLinkedList(std::vector<int>{1, 1, 2, 3, 3});
  leetcode::ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> actual = leetcode::traverse(result);
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(expected, actual);
}

TEST_P(RemoveDuplicatesFromSortedListTest, SelfAuthoredEmptyList) {
  leetcode::ListNode* result = solution.deleteDuplicates(nullptr);
  EXPECT_EQ(nullptr, result);
}

TEST_P(RemoveDuplicatesFromSortedListTest, SelfAuthoredSingleNode) {
  leetcode::ListNode* head = leetcode::constructLinkedList(std::vector<int>{5});
  leetcode::ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> actual = leetcode::traverse(result);
  std::vector<int> expected = {5};
  EXPECT_EQ(expected, actual);
}

TEST_P(RemoveDuplicatesFromSortedListTest, SelfAuthoredNoDuplicates) {
  leetcode::ListNode* head =
      leetcode::constructLinkedList(std::vector<int>{1, 2, 3});
  leetcode::ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> actual = leetcode::traverse(result);
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicatesFromSortedListTestCases, RemoveDuplicatesFromSortedListTest,
    ::testing::ValuesIn(
        RemoveDuplicatesFromSortedListSolution().getStrategyNames()));

}  // namespace problem_83
}  // namespace leetcode
