#include "leetcode/problems/minimum-recolors-to-get-k-consecutive-black-blocks.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_2379 {

class MinimumRecolorsToGetKConsecutiveBlackBlocksTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumRecolorsToGetKConsecutiveBlackBlocksSolution solution_;
};

TEST_P(MinimumRecolorsToGetKConsecutiveBlackBlocksTest, Example1) {
  EXPECT_EQ(3, solution_.minimumRecolors("WBBWWBBWBW", 7));
}

TEST_P(MinimumRecolorsToGetKConsecutiveBlackBlocksTest, Example2) {
  EXPECT_EQ(0, solution_.minimumRecolors("WBWBBBW", 2));
}

TEST_P(MinimumRecolorsToGetKConsecutiveBlackBlocksTest, SelfAuthored1) {
  EXPECT_EQ(1, solution_.minimumRecolors("WWBBB", 4));
}

TEST_P(MinimumRecolorsToGetKConsecutiveBlackBlocksTest, SelfAuthored2) {
  EXPECT_EQ(0, solution_.minimumRecolors("BBBB", 3));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumRecolorsToGetKConsecutiveBlackBlocksTestCases,
    MinimumRecolorsToGetKConsecutiveBlackBlocksTest,
    ::testing::ValuesIn(
        MinimumRecolorsToGetKConsecutiveBlackBlocksSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2379
