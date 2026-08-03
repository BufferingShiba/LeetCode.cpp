#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/reaching-points.h"

namespace leetcode {
namespace problem_780 {

class ReachingPointsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReachingPointsSolution solution_;
};

TEST_P(ReachingPointsTest, Example1) {
  EXPECT_TRUE(solution_.reachingPoints(1, 1, 3, 5));
}

TEST_P(ReachingPointsTest, Example2) {
  EXPECT_FALSE(solution_.reachingPoints(1, 1, 2, 2));
}

TEST_P(ReachingPointsTest, Example3) {
  EXPECT_TRUE(solution_.reachingPoints(1, 1, 1, 1));
}

TEST_P(ReachingPointsTest, SelfAuthoredLargerValues) {
  EXPECT_TRUE(solution_.reachingPoints(1, 1, 1000000000, 1));
  EXPECT_FALSE(solution_.reachingPoints(2, 3, 10, 4));
}

INSTANTIATE_TEST_SUITE_P(
    ReachingPointsStrategies, ReachingPointsTest,
    ::testing::ValuesIn(ReachingPointsSolution().getStrategyNames()));

}  // namespace problem_780
}  // namespace leetcode
