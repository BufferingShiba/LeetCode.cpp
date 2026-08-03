#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/number-of-squareful-arrays.h"

using namespace leetcode::problem_996;

class NumberOfSquarefulArraysTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NumberOfSquarefulArraysSolution solution;
};

TEST_P(NumberOfSquarefulArraysTest, Example1) {
  std::vector<int> nums = {1, 17, 8};
  EXPECT_EQ(solution.numSquarefulPerms(nums), 2);
}

TEST_P(NumberOfSquarefulArraysTest, Example2) {
  std::vector<int> nums = {2, 2, 2};
  EXPECT_EQ(solution.numSquarefulPerms(nums), 1);
}

TEST_P(NumberOfSquarefulArraysTest, SingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.numSquarefulPerms(nums), 0);
}

TEST_P(NumberOfSquarefulArraysTest, TwoElementsSquareful) {
  std::vector<int> nums = {1, 3};
  // [1,3] and [3,1] are both valid (1+3=4=2^2)
  EXPECT_EQ(solution.numSquarefulPerms(nums), 2);
}

TEST_P(NumberOfSquarefulArraysTest, TwoElementsNotSquareful) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution.numSquarefulPerms(nums), 0);
}

TEST_P(NumberOfSquarefulArraysTest, SelfAuthoredWithDuplicates) {
  std::vector<int> nums = {2, 2, 3};
  // Valid permutations: [2,2,3] is not (2+2=4 ok, 2+3=5 not).
  // [2,3,2]: 2+3=5 not. [3,2,2]: 3+2=5 not.
  // Actually none: 2+2=4 ok, but 2+3=5 not square. So answer 0.
  EXPECT_EQ(solution.numSquarefulPerms(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    NumberOfSquarefulArraysTest,
    testing::ValuesIn(
        NumberOfSquarefulArraysSolution().getStrategyNames()));
