#include <gtest/gtest.h>
#include "leetcode/problems/count-odd-numbers-in-an-interval-range.h"
#include <vector>
#include <string>

namespace leetcode {
namespace problem_1523 {

class CountOddNumbersInAnIntervalRangeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountOddNumbersInAnIntervalRangeSolution solution;
};

TEST_P(CountOddNumbersInAnIntervalRangeTest, Example1) {
  EXPECT_EQ(3, solution.countOdds(3, 7));
}

TEST_P(CountOddNumbersInAnIntervalRangeTest, Example2) {
  EXPECT_EQ(1, solution.countOdds(8, 10));
}

TEST_P(CountOddNumbersInAnIntervalRangeTest, SelfAuthoredSameNumberOdd) {
  EXPECT_EQ(1, solution.countOdds(5, 5));
}

TEST_P(CountOddNumbersInAnIntervalRangeTest, SelfAuthoredSameNumberEven) {
  EXPECT_EQ(0, solution.countOdds(4, 4));
}

TEST_P(CountOddNumbersInAnIntervalRangeTest, SelfAuthoredZeroToZero) {
  EXPECT_EQ(0, solution.countOdds(0, 0));
}

INSTANTIATE_TEST_SUITE_P(
    CountOddNumbersInAnIntervalRangeTestSuite,
    CountOddNumbersInAnIntervalRangeTest,
    ::testing::ValuesIn(
        CountOddNumbersInAnIntervalRangeSolution().getStrategyNames()));

}  // namespace problem_1523
}  // namespace leetcode
