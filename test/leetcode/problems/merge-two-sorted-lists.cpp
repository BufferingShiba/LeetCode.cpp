#include <gtest/gtest.h>

#include "leetcode/problems/merge-two-sorted-lists.h"

namespace leetcode::problem_21 {

class MergeTwoSortedListsTest : public ::testing::TestWithParam<std::string> {
 protected:
  MergeTwoSortedListsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MergeTwoSortedListsTest, Example1) {
  auto* list1 = constructLinkedList(std::vector<int>{1, 2, 4});
  auto* list2 = constructLinkedList(std::vector<int>{1, 3, 4});
  auto* result = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(traverse(result), (std::vector<int>{1, 1, 2, 3, 4, 4}));
}

TEST_P(MergeTwoSortedListsTest, Example2) {
  auto* list1 = constructLinkedList(std::vector<int>{});
  auto* list2 = constructLinkedList(std::vector<int>{});
  auto* result = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(traverse(result), (std::vector<int>{}));
}

TEST_P(MergeTwoSortedListsTest, Example3) {
  auto* list1 = constructLinkedList(std::vector<int>{});
  auto* list2 = constructLinkedList(std::vector<int>{0});
  auto* result = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(traverse(result), (std::vector<int>{0}));
}

TEST_P(MergeTwoSortedListsTest, SelfAuthoredOneListEmpty) {
  auto* list1 = constructLinkedList(std::vector<int>{5});
  auto* list2 = constructLinkedList(std::vector<int>{});
  auto* result = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(traverse(result), (std::vector<int>{5}));
}

TEST_P(MergeTwoSortedListsTest, SelfAuthoredInterleaving) {
  auto* list1 = constructLinkedList(std::vector<int>{1, 3, 5});
  auto* list2 = constructLinkedList(std::vector<int>{2, 4, 6});
  auto* result = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(traverse(result), (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MergeTwoSortedListsTest,
    ::testing::ValuesIn(MergeTwoSortedListsSolution().getStrategyNames()));

}  // namespace leetcode::problem_21
