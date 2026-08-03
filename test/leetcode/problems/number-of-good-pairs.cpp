#include <gtest/gtest.h>

#include "leetcode/problems/number-of-good-pairs.h"

#include <string>
#include <vector>

namespace leetcode::problem_1512 {

class NumberOfGoodPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfGoodPairsSolution solution;
};

TEST_P(NumberOfGoodPairsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 1, 1, 3};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 4);
}

TEST_P(NumberOfGoodPairsTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 6);
}

TEST_P(NumberOfGoodPairsTest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 0);
}

TEST_P(NumberOfGoodPairsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 0);
}

TEST_P(NumberOfGoodPairsTest, SelfAuthoredTwoSameValues) {
  std::vector<int> nums = {5, 5};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 1);
}

TEST_P(NumberOfGoodPairsTest, SelfAuthoredMixedValues) {
  std::vector<int> nums = {1, 1, 2, 2, 2};
  EXPECT_EQ(solution.numIdenticalPairs(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfGoodPairsTestSuite, NumberOfGoodPairsTest,
    ::testing::ValuesIn(NumberOfGoodPairsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1512
