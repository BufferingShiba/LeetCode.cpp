#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-balloons.h"

namespace leetcode::problem_1189 {

class MaximumNumberOfBalloonsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfBalloonsSolution solution_;
};

TEST_P(MaximumNumberOfBalloonsTest, Example1) {
  EXPECT_EQ(solution_.maxNumberOfBalloons("nlaebolko"), 1);
}

TEST_P(MaximumNumberOfBalloonsTest, Example2) {
  EXPECT_EQ(solution_.maxNumberOfBalloons("loonbalxballpoon"), 2);
}

TEST_P(MaximumNumberOfBalloonsTest, Example3) {
  EXPECT_EQ(solution_.maxNumberOfBalloons("leetcode"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfBalloonsTestSuite, MaximumNumberOfBalloonsTest,
    ::testing::ValuesIn(MaximumNumberOfBalloonsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1189
