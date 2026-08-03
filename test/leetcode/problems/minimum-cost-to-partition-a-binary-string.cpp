#include "leetcode/problems/minimum-cost-to-partition-a-binary-string.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3864 {

class MinimumCostToPartitionABinaryStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToPartitionABinaryStringSolution solution;
};

TEST_P(MinimumCostToPartitionABinaryStringTest, Example1) {
  EXPECT_EQ(6, solution.minCost("1010", 2, 1));
}

TEST_P(MinimumCostToPartitionABinaryStringTest, Example2) {
  EXPECT_EQ(12, solution.minCost("1010", 3, 10));
}

TEST_P(MinimumCostToPartitionABinaryStringTest, Example3) {
  EXPECT_EQ(2, solution.minCost("00", 1, 2));
}

TEST_P(MinimumCostToPartitionABinaryStringTest, SelfAuthoredSingleSensitive) {
  EXPECT_EQ(7, solution.minCost("1", 7, 3));
}

TEST_P(MinimumCostToPartitionABinaryStringTest, SelfAuthoredAllSensitive) {
  EXPECT_EQ(4, solution.minCost("1111", 1, 10));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToPartitionABinaryStringTestSuite,
    MinimumCostToPartitionABinaryStringTest,
    ::testing::ValuesIn(MinimumCostToPartitionABinaryStringSolution()
                            .getStrategyNames()));

}  // namespace problem_3864
}  // namespace leetcode
