#include "leetcode/problems/find-the-number-of-good-pairs-ii.h"

#include <gtest/gtest.h>

using leetcode::problem_3164::FindTheNumberOfGoodPairsIiSolution;

class FindTheNumberOfGoodPairsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheNumberOfGoodPairsIiSolution solution;
};

TEST_P(FindTheNumberOfGoodPairsIiTest, Example1) {
  std::vector<int> nums1{1, 3, 4};
  std::vector<int> nums2{1, 3, 4};
  EXPECT_EQ(5, solution.numberOfPairs(nums1, nums2, 1));
}

TEST_P(FindTheNumberOfGoodPairsIiTest, Example2) {
  std::vector<int> nums1{1, 2, 4, 12};
  std::vector<int> nums2{2, 4};
  EXPECT_EQ(2, solution.numberOfPairs(nums1, nums2, 3));
}

TEST_P(FindTheNumberOfGoodPairsIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums1{6};
  std::vector<int> nums2{3};
  EXPECT_EQ(1, solution.numberOfPairs(nums1, nums2, 1));
}

TEST_P(FindTheNumberOfGoodPairsIiTest, SelfAuthoredKNotMatching) {
  std::vector<int> nums1{10};
  std::vector<int> nums2{5};
  // 5*3=15 does not divide 10, and 5 continues: 10 % (5*3)=10 != 0.
  EXPECT_EQ(0, solution.numberOfPairs(nums1, nums2, 3));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNumberOfGoodPairsIiTestSuite, FindTheNumberOfGoodPairsIiTest,
    ::testing::ValuesIn(FindTheNumberOfGoodPairsIiSolution().getStrategyNames()));
