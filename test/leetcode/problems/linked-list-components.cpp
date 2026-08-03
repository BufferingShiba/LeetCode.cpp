#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/linked-list-components.h"

namespace leetcode {
namespace problem_817 {

class LinkedListComponentsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LinkedListComponentsSolution solution;
};

TEST_P(LinkedListComponentsTest, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{0, 1, 2, 3});
  std::vector<int> nums{0, 1, 3};
  EXPECT_EQ(2, solution.numComponents(head, nums));
}

TEST_P(LinkedListComponentsTest, Example2) {
  ListNode* head =
      constructLinkedList(std::vector<int>{0, 1, 2, 3, 4});
  std::vector<int> nums{0, 3, 1, 4};
  EXPECT_EQ(2, solution.numComponents(head, nums));
}

TEST_P(LinkedListComponentsTest, SelfAuthoredAllNodesInNums) {
  ListNode* head = constructLinkedList(std::vector<int>{0, 1, 2});
  std::vector<int> nums{0, 1, 2};
  EXPECT_EQ(1, solution.numComponents(head, nums));
}

TEST_P(LinkedListComponentsTest, SelfAuthoredAlternatingComponents) {
  ListNode* head = constructLinkedList(std::vector<int>{0, 1, 2, 3, 4});
  std::vector<int> nums{0, 2, 4};
  EXPECT_EQ(3, solution.numComponents(head, nums));
}

TEST_P(LinkedListComponentsTest, SelfAuthoredSingleNodeInNums) {
  ListNode* head = constructLinkedList(std::vector<int>{0});
  std::vector<int> nums{0};
  EXPECT_EQ(1, solution.numComponents(head, nums));
}

INSTANTIATE_TEST_SUITE_P(
    LinkedListComponentsTestSuite, LinkedListComponentsTest,
    ::testing::ValuesIn(LinkedListComponentsSolution().getStrategyNames()));

}  // namespace problem_817
}  // namespace leetcode
