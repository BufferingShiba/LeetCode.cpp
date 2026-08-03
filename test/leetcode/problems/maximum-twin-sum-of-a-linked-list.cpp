#include "leetcode/problems/maximum-twin-sum-of-a-linked-list.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2130 {

class MaximumTwinSumOfALinkedListTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumTwinSumOfALinkedListSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  head = [5,4,2,1]
// Output: 6
TEST_P(MaximumTwinSumOfALinkedListTest, OfficialExample1) {
  ListNode* head = leetcode::constructLinkedList({5, 4, 2, 1});
  int expected = 6;
  int actual = solution.pairSum(head);
  EXPECT_EQ(expected, actual);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  head = [4,2,2,3]
// Output: 7
TEST_P(MaximumTwinSumOfALinkedListTest, OfficialExample2) {
  ListNode* head = leetcode::constructLinkedList({4, 2, 2, 3});
  int expected = 7;
  int actual = solution.pairSum(head);
  EXPECT_EQ(expected, actual);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  head = [1,100000]
// Output: 100001
TEST_P(MaximumTwinSumOfALinkedListTest, OfficialExample3) {
  ListNode* head = leetcode::constructLinkedList({1, 100000});
  int expected = 100001;
  int actual = solution.pairSum(head);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumTwinSumOfALinkedListTest,
    ::testing::ValuesIn(MaximumTwinSumOfALinkedListSolution().getStrategyNames()));

}  // namespace problem_2130
}  // namespace leetcode
