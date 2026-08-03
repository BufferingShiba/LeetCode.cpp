#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/flip-string-to-monotone-increasing.h"

namespace leetcode {
namespace problem_926 {

using FlipStringToMonotoneIncreasingTest = ::testing::TestWithParam<std::string>;

INSTANTIATE_TEST_SUITE_P(
    FlipStringToMonotoneIncreasingStrategies, FlipStringToMonotoneIncreasingTest,
    ::testing::ValuesIn(FlipStringToMonotoneIncreasingSolution().getStrategyNames()));

TEST_P(FlipStringToMonotoneIncreasingTest, Example1) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("00110"), 1);
}

TEST_P(FlipStringToMonotoneIncreasingTest, Example2) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("010110"), 2);
}

TEST_P(FlipStringToMonotoneIncreasingTest, Example3) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("00011000"), 2);
}

TEST_P(FlipStringToMonotoneIncreasingTest, AllZeros) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("0000"), 0);
}

TEST_P(FlipStringToMonotoneIncreasingTest, AllOnes) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("1111"), 0);
}

TEST_P(FlipStringToMonotoneIncreasingTest, SingleZeroThenOne) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("10"), 1);
}

TEST_P(FlipStringToMonotoneIncreasingTest, SingleChar) {
  FlipStringToMonotoneIncreasingSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.minFlipsMonoIncr("0"), 0);
  EXPECT_EQ(solution.minFlipsMonoIncr("1"), 0);
}

}  // namespace problem_926
}  // namespace leetcode
