#include "leetcode/problems/add-two-numbers.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2 {

class AddTwoNumbersTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AddTwoNumbersSolution solution;
};

TEST_P(AddTwoNumbersTest, Example1) {
  ListNode* l1 = constructLinkedList({2, 4, 3});
  ListNode* l2 = constructLinkedList({5, 6, 4});
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {7, 0, 8};
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

TEST_P(AddTwoNumbersTest, Example2) {
  ListNode* l1 = constructLinkedList({0});
  ListNode* l2 = constructLinkedList({0});
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {0};
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

TEST_P(AddTwoNumbersTest, Example3) {
  ListNode* l1 = constructLinkedList({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = constructLinkedList({9, 9, 9, 9});
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {8, 9, 9, 9, 0, 0, 0, 1};
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

TEST_P(AddTwoNumbersTest, DifferentLength) {
  ListNode* l1 = constructLinkedList({1, 2, 3});  // 321
  ListNode* l2 = constructLinkedList({4, 5});     // 54
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {5, 7, 3};  // 321 + 54 = 375 -> [5,7,3]
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

TEST_P(AddTwoNumbersTest, CarryAtEnd) {
  ListNode* l1 = constructLinkedList({9, 9});  // 99
  ListNode* l2 = constructLinkedList({1});     // 1
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {0, 0, 1};  // 99 + 1 = 100 -> [0,0,1]
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

TEST_P(AddTwoNumbersTest, OneEmptyList) {
  ListNode* l1 = constructLinkedList({});         // 0
  ListNode* l2 = constructLinkedList({1, 2, 3});  // 321
  ListNode* result = solution.addTwoNumbers(l1, l2);
  vector<int> expected = {1, 2, 3};  // 0 + 321 = 321
  vector<int> actual = traverse(result);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, AddTwoNumbersTest,
    ::testing::ValuesIn(AddTwoNumbersSolution().getStrategyNames()));

}  // namespace problem_2
}  // namespace leetcode