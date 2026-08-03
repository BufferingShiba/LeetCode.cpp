#include "leetcode/problems/make-array-zero-by-subtracting-equal-amounts.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2357 {

class MakeArrayZeroBySubtractingEqualAmountsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MakeArrayZeroBySubtractingEqualAmountsSolution solution;
};

TEST_P(MakeArrayZeroBySubtractingEqualAmountsTest, Example1) {
  std::vector<int> nums{1, 5, 0, 3, 5};
  EXPECT_EQ(3, solution.minimumOperations(nums));
}

TEST_P(MakeArrayZeroBySubtractingEqualAmountsTest, Example2) {
  std::vector<int> nums{0};
  EXPECT_EQ(0, solution.minimumOperations(nums));
}

TEST_P(MakeArrayZeroBySubtractingEqualAmountsTest, AllSameNonZero) {
  std::vector<int> nums{2, 2, 2};
  EXPECT_EQ(1, solution.minimumOperations(nums));
}

TEST_P(MakeArrayZeroBySubtractingEqualAmountsTest, AllZero) {
  std::vector<int> nums{0, 0, 0, 0};
  EXPECT_EQ(0, solution.minimumOperations(nums));
}

TEST_P(MakeArrayZeroBySubtractingEqualAmountsTest, SingleNonZero) {
  std::vector<int> nums{7};
  EXPECT_EQ(1, solution.minimumOperations(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MakeArrayZeroBySubtractingEqualAmountsTestSuite,
    MakeArrayZeroBySubtractingEqualAmountsTest,
    ::testing::ValuesIn(
        MakeArrayZeroBySubtractingEqualAmountsSolution().getStrategyNames()));

}  // namespace problem_2357
}  // namespace leetcode
