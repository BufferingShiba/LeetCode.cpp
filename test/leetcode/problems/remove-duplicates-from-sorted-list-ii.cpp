#include "leetcode/problems/remove-duplicates-from-sorted-list-ii.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_82 {

class RemoveDuplicatesFromSortedListIiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveDuplicatesFromSortedListIiSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
TEST_P(RemoveDuplicatesFromSortedListIiTest, OfficialExample1) {
  ListNode* head = leetcode::constructLinkedList({1, 2, 3, 3, 4, 4, 5});
  ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> expected{1, 2, 5};
  EXPECT_EQ(expected, leetcode::traverse(result));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  head = [1,1,1,2,3]
// Output: [2,3]
TEST_P(RemoveDuplicatesFromSortedListIiTest, OfficialExample2) {
  ListNode* head = leetcode::constructLinkedList({1, 1, 1, 2, 3});
  ListNode* result = solution.deleteDuplicates(head);
  std::vector<int> expected{2, 3};
  EXPECT_EQ(expected, leetcode::traverse(result));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, RemoveDuplicatesFromSortedListIiTest,
    ::testing::ValuesIn(RemoveDuplicatesFromSortedListIiSolution().getStrategyNames()));

}  // namespace problem_82
}  // namespace leetcode
