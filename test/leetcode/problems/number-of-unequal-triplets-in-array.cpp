#include <gtest/gtest.h>

#include "leetcode/problems/number-of-unequal-triplets-in-array.h"

namespace leetcode {
namespace problem_2475 {
namespace {

class NumberOfUnequalTripletsInArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfUnequalTripletsInArraySolution solution;
};

TEST_P(NumberOfUnequalTripletsInArrayTest, Example1) {
  std::vector<int> nums = {4, 4, 2, 4, 3};
  EXPECT_EQ(3, solution.unequalTriplets(nums));
}

TEST_P(NumberOfUnequalTripletsInArrayTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  EXPECT_EQ(0, solution.unequalTriplets(nums));
}

TEST_P(NumberOfUnequalTripletsInArrayTest, SelfAuthoredAllDistinctThree) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(1, solution.unequalTriplets(nums));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfUnequalTripletsInArrayTestSuite,
    NumberOfUnequalTripletsInArrayTest,
    ::testing::ValuesIn(
        NumberOfUnequalTripletsInArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2475
}  // namespace leetcode
