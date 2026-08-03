#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/linked-list-cycle.h"

namespace leetcode {
namespace problem_141 {
namespace {

// Helper: construct a (possibly cyclic) linked list.
// nums = node values, pos = index of the node that tail->next connects to.
// pos == -1 means acyclic.
ListNode *constructCyclicList(const std::vector<int> &nums, int pos) {
  ListNode *head = constructLinkedList(nums);
  if (pos >= 0 && head != nullptr) {
    ListNode *tail = getTail(head);
    ListNode *entry = getNode(head, pos);
    tail->next = entry;
  }
  return head;
}

class LinkedListCycleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  LinkedListCycleSolution solution;
};

TEST_P(LinkedListCycleTest, Example1Cycle) {
  ListNode *head = constructCyclicList({3, 2, 0, -4}, 1);
  EXPECT_TRUE(solution.hasCycle(head));
}

TEST_P(LinkedListCycleTest, Example2Cycle) {
  ListNode *head = constructCyclicList({1, 2}, 0);
  EXPECT_TRUE(solution.hasCycle(head));
}

TEST_P(LinkedListCycleTest, Example3NoCycle) {
  ListNode *head = constructCyclicList({1}, -1);
  EXPECT_FALSE(solution.hasCycle(head));
}

TEST_P(LinkedListCycleTest, SelfAuthoredEmptyListNoCycle) {
  ListNode *head = nullptr;
  EXPECT_FALSE(solution.hasCycle(head));
}

INSTANTIATE_TEST_SUITE_P(
    LinkedListCycleTestSuite, LinkedListCycleTest,
    ::testing::ValuesIn(LinkedListCycleSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_141
}  // namespace leetcode
