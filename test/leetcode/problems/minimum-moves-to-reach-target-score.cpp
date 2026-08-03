#include "leetcode/problems/minimum-moves-to-reach-target-score.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_2139 {

class MinimumMovesToReachTargetScoreTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumMovesToReachTargetScoreSolution solution_;
};

TEST_P(MinimumMovesToReachTargetScoreTest, Example1) {
  EXPECT_EQ(solution_.minMoves(5, 0), 4);
}

TEST_P(MinimumMovesToReachTargetScoreTest, Example2) {
  EXPECT_EQ(solution_.minMoves(19, 2), 7);
}

TEST_P(MinimumMovesToReachTargetScoreTest, Example3) {
  EXPECT_EQ(solution_.minMoves(10, 4), 4);
}

TEST_P(MinimumMovesToReachTargetScoreTest, SelfAuthoredTargetIsOne) {
  EXPECT_EQ(solution_.minMoves(1, 100), 0);
}

TEST_P(MinimumMovesToReachTargetScoreTest, SelfAuthoredNoDoubles) {
  EXPECT_EQ(solution_.minMoves(7, 0), 6);
}

TEST_P(MinimumMovesToReachTargetScoreTest, SelfAuthoredDoubleOnly) {
  // 1 -> 2 -> 4 -> 8 (3 doubles)
  EXPECT_EQ(solution_.minMoves(8, 3), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumMovesToReachTargetScoreTestSuite,
    MinimumMovesToReachTargetScoreTest,
    ::testing::ValuesIn(
        MinimumMovesToReachTargetScoreSolution().getStrategyNames()));

}  // namespace leetcode::problem_2139
