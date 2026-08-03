
#include "leetcode/problems/count-total-number-of-colored-cells.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2579 {

class CountTotalNumberOfColoredCellsTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTotalNumberOfColoredCellsSolution solution;
};

TEST_P(CountTotalNumberOfColoredCellsTest, Example1) {
  int n = 1;
  long long expected = 1;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

TEST_P(CountTotalNumberOfColoredCellsTest, Example2) {
  int n = 2;
  long long expected = 5;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

// n=3: 1 + 4 + 8 = 13
TEST_P(CountTotalNumberOfColoredCellsTest, SelfAuthoredN3) {
  int n = 3;
  long long expected = 13;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

// n=4: 13 + 12 = 25
TEST_P(CountTotalNumberOfColoredCellsTest, SelfAuthoredN4) {
  int n = 4;
  long long expected = 25;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

// n=5: 25 + 16 = 41
TEST_P(CountTotalNumberOfColoredCellsTest, SelfAuthoredN5) {
  int n = 5;
  long long expected = 41;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

// 大 n，验证 long long 足够容纳 2*10^10
TEST_P(CountTotalNumberOfColoredCellsTest, SelfAuthoredLargeN) {
  int n = 100000;
  long long expected = 2LL * 100000LL * 100000LL - 2LL * 100000LL + 1LL;
  EXPECT_EQ(expected, solution.coloredCells(n));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountTotalNumberOfColoredCellsTest,
    ::testing::ValuesIn(
        CountTotalNumberOfColoredCellsSolution().getStrategyNames()));

}  // namespace problem_2579
}  // namespace leetcode
