#include <gtest/gtest.h>

#include "leetcode/problems/wiggle-subsequence.h"

using namespace leetcode::problem_376;

class WiggleSubsequenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  WiggleSubsequenceSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(WiggleSubsequenceTest, Example1) {
  std::vector<int> nums = {1, 7, 4, 9, 2, 5};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 6);
}

TEST_P(WiggleSubsequenceTest, Example2) {
  std::vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 7);
}

TEST_P(WiggleSubsequenceTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 2);
}

TEST_P(WiggleSubsequenceTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 1);
}

TEST_P(WiggleSubsequenceTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {3, 3, 3, 3};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 1);
}

TEST_P(WiggleSubsequenceTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {1, 5};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 2);
}

TEST_P(WiggleSubsequenceTest, SelfAuthoredFlatThenWiggle) {
  std::vector<int> nums = {1, 1, 1, 2, 1};
  EXPECT_EQ(solution.wiggleMaxLength(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, WiggleSubsequenceTest,
                         ::testing::ValuesIn(WiggleSubsequenceSolution()
                                                 .getStrategyNames()));
