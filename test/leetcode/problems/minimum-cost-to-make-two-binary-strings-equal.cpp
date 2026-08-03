#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-to-make-two-binary-strings-equal.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3800 {
namespace {

class MinimumCostToMakeTwoBinaryStringsEqualTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToMakeTwoBinaryStringsEqualSolution solution;
};

TEST_P(MinimumCostToMakeTwoBinaryStringsEqualTest, Example1) {
  EXPECT_EQ(16, solution.minimumCost("01000", "10111", 10, 2, 2));
}

TEST_P(MinimumCostToMakeTwoBinaryStringsEqualTest, Example2) {
  EXPECT_EQ(6, solution.minimumCost("001", "110", 2, 100, 100));
}

TEST_P(MinimumCostToMakeTwoBinaryStringsEqualTest, Example3) {
  EXPECT_EQ(0, solution.minimumCost("1010", "1010", 5, 5, 5));
}

TEST_P(MinimumCostToMakeTwoBinaryStringsEqualTest, Corners) {
  // Single equal character.
  EXPECT_EQ(0, solution.minimumCost("0", "0", 1, 1, 1));
  // Single different character: flip one bit.
  EXPECT_EQ(3, solution.minimumCost("0", "1", 3, 100, 100));
  // Single different character, expensive flip.
  EXPECT_EQ(5, solution.minimumCost("0", "1", 5, 100, 100));
  // Two opposite differences: swap clears both if cheapest.
  EXPECT_EQ(1, solution.minimumCost("01", "10", 5, 1, 5));
}

TEST_P(MinimumCostToMakeTwoBinaryStringsEqualTest, CrossHelps) {
  // Single diff always needs a flip (cross alone cannot clear it).
  EXPECT_EQ(5, solution.minimumCost("00", "10", 5, 100, 1));
  // Three same-side diffs, cross+swap cheap: 1 cross -> one opposite pair via
  // swap, one left flip. cost = cross(1)+swap(1)+flip(100)=102.
  EXPECT_EQ(102, solution.minimumCost("000", "111", 100, 1, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMakeTwoBinaryStringsEqualTestParameters,
    MinimumCostToMakeTwoBinaryStringsEqualTest,
    ::testing::ValuesIn(
        MinimumCostToMakeTwoBinaryStringsEqualSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3800
}  // namespace leetcode
