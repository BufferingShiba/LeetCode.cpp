#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/pass-the-pillow.h"

namespace leetcode {
namespace problem_2582 {

class PassThePillowTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PassThePillowSolution solution;
};

TEST_P(PassThePillowTest, Example1) {
  EXPECT_EQ(solution.passThePillow(4, 5), 2);
}

TEST_P(PassThePillowTest, Example2) {
  EXPECT_EQ(solution.passThePillow(3, 2), 3);
}

TEST_P(PassThePillowTest, SelfAuthoredBackToStart) {
  // cycle length = 2*(n-1) = 6, returns to person 1
  EXPECT_EQ(solution.passThePillow(4, 6), 1);
}

TEST_P(PassThePillowTest, SelfAuthoredEndOfForward) {
  EXPECT_EQ(solution.passThePillow(4, 3), 4);
}

TEST_P(PassThePillowTest, SelfAuthoredReverseDirection) {
  // 1->2->3->4->3->2->1->2, at time=7 -> 2
  EXPECT_EQ(solution.passThePillow(4, 7), 2);
}

INSTANTIATE_TEST_SUITE_P(
    PassThePillowTestSuite, PassThePillowTest,
    ::testing::ValuesIn(PassThePillowSolution().getStrategyNames()));

}  // namespace problem_2582
}  // namespace leetcode
