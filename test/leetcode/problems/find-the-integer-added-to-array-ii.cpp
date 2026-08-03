#include <gtest/gtest.h>

#include "leetcode/problems/find-the-integer-added-to-array-ii.h"

using namespace leetcode::problem_3132;

class FindTheIntegerAddedToArrayIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindTheIntegerAddedToArrayIiSolution solution;
};

TEST_P(FindTheIntegerAddedToArrayIiTest, Example1) {
  std::vector<int> nums1 = {4, 20, 16, 12, 8};
  std::vector<int> nums2 = {14, 18, 10};
  EXPECT_EQ(solution.minimumAddedInteger(nums1, nums2), -2);
}

TEST_P(FindTheIntegerAddedToArrayIiTest, Example2) {
  std::vector<int> nums1 = {3, 5, 5, 3};
  std::vector<int> nums2 = {7, 7};
  EXPECT_EQ(solution.minimumAddedInteger(nums1, nums2), 2);
}

TEST_P(FindTheIntegerAddedToArrayIiTest, MinimumLength) {
  // n1 = 3, n2 = 1, remove 2 elements
  std::vector<int> nums1 = {10, 5, 8};
  std::vector<int> nums2 = {12};
  // sorted: a=[5,8,10], b=[12]
  // x=7: keep 5, remove 8,10 → 5+7=12 ✓
  // x=4: keep 8, remove 5,10 → 8+4=12 ✓
  // x=2: keep 10, remove 5,8 → 10+2=12 ✓
  // min x = 2
  EXPECT_EQ(solution.minimumAddedInteger(nums1, nums2), 2);
}

TEST_P(FindTheIntegerAddedToArrayIiTest, AllSameValues) {
  std::vector<int> nums1 = {0, 0, 0, 0, 0};
  std::vector<int> nums2 = {5, 5, 5};
  // x = 5-0 = 5
  EXPECT_EQ(solution.minimumAddedInteger(nums1, nums2), 5);
}

TEST_P(FindTheIntegerAddedToArrayIiTest, MultipleCandidates) {
  // 多个 x 候选都可行，取最小
  std::vector<int> nums1 = {100, 200, 300, 400};
  std::vector<int> nums2 = {50, 150};
  // x=-50:  keep 100,200 → 50,150; remove 300,400
  // x=-150: keep 200,300 → 50,150; remove 100,400
  // x=-250: keep 300,400 → 50,150; remove 100,200
  // min = -250
  EXPECT_EQ(solution.minimumAddedInteger(nums1, nums2), -250);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheIntegerAddedToArrayIiTest,
    testing::ValuesIn(
        FindTheIntegerAddedToArrayIiSolution().getStrategyNames()));
