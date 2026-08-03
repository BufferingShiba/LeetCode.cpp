#include <gtest/gtest.h>

#include "leetcode/problems/find-sum-of-array-product-of-magical-sequences.h"

using namespace leetcode::problem_3539;

class FindSumOfArrayProductOfMagicalSequencesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindSumOfArrayProductOfMagicalSequencesSolution solution;
};

TEST_P(FindSumOfArrayProductOfMagicalSequencesTest, Example1) {
  std::vector<int> nums = {1, 10, 100, 10000, 1000000};
  EXPECT_EQ(solution.magicalSum(5, 5, nums), 991600007);
}

TEST_P(FindSumOfArrayProductOfMagicalSequencesTest, Example2) {
  std::vector<int> nums = {5, 4, 3, 2, 1};
  EXPECT_EQ(solution.magicalSum(2, 2, nums), 170);
}

TEST_P(FindSumOfArrayProductOfMagicalSequencesTest, Example3) {
  std::vector<int> nums = {28};
  EXPECT_EQ(solution.magicalSum(1, 1, nums), 28);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindSumOfArrayProductOfMagicalSequencesTest,
    testing::ValuesIn(
        FindSumOfArrayProductOfMagicalSequencesSolution().getStrategyNames()));
