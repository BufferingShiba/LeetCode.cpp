#include <gtest/gtest.h>

#include "leetcode/problems/sort-list.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_148 {

class SortListTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  SortListSolution solution_;
};

TEST_P(SortListTest, Example1) {
  std::vector<int> input{4, 2, 1, 3};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4}));
}

TEST_P(SortListTest, Example2) {
  std::vector<int> input{-1, 5, 3, 4, 0};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{-1, 0, 3, 4, 5}));
}

TEST_P(SortListTest, Example3Empty) {
  ListNode* head = nullptr;
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_TRUE(result.empty());
}

TEST_P(SortListTest, SelfAuthoredSingleNode) {
  std::vector<int> input{7};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{7}));
}

TEST_P(SortListTest, SelfAuthoredAlreadySorted) {
  std::vector<int> input{1, 2, 3, 4, 5};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST_P(SortListTest, SelfAuthoredReverseSorted) {
  std::vector<int> input{5, 4, 3, 2, 1};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST_P(SortListTest, SelfAuthoredDuplicates) {
  std::vector<int> input{3, 1, 2, 1, 3};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{1, 1, 2, 3, 3}));
}

TEST_P(SortListTest, SelfAuthoredNegativesAndPositives) {
  std::vector<int> input{-3, 5, 0, -1, 2, -4};
  ListNode* head = leetcode::constructLinkedList(input);
  ListNode* sorted = solution_.sortList(head);
  std::vector<int> result = leetcode::traverse(sorted);
  EXPECT_EQ(result, (std::vector<int>{-4, -3, -1, 0, 2, 5}));
}

INSTANTIATE_TEST_SUITE_P(SortListStrategies, SortListTest,
                         ::testing::ValuesIn(SortListSolution().getStrategyNames()));

}  // namespace problem_148
}  // namespace leetcode
