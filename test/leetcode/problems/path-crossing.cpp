#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/path-crossing.h"

namespace leetcode::problem_1496 {

class PathCrossingTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PathCrossingSolution solution_;
};

TEST_P(PathCrossingTest, Example1) {
  EXPECT_FALSE(solution_.isPathCrossing("NES"));
}

TEST_P(PathCrossingTest, Example2) {
  EXPECT_TRUE(solution_.isPathCrossing("NESWW"));
}

TEST_P(PathCrossingTest, SelfAuthoredSingleMoveNoCross) {
  EXPECT_FALSE(solution_.isPathCrossing("N"));
}

TEST_P(PathCrossingTest, SelfAuthoredStraightLineNoCross) {
  EXPECT_FALSE(solution_.isPathCrossing("NNNN"));
}

INSTANTIATE_TEST_SUITE_P(
    PathCrossingStrategies, PathCrossingTest,
    ::testing::ValuesIn(PathCrossingSolution().getStrategyNames()));

}  // namespace leetcode::problem_1496
