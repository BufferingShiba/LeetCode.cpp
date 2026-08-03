#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/teemo-attacking.h"

namespace leetcode {
namespace problem_495 {

class TeemoAttackingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TeemoAttackingSolution solution_;
};

TEST_P(TeemoAttackingTest, Example1) {
  std::vector<int> timeSeries = {1, 4};
  int duration = 2;
  EXPECT_EQ(4, solution_.findPoisonedDuration(timeSeries, duration));
}

TEST_P(TeemoAttackingTest, Example2) {
  std::vector<int> timeSeries = {1, 2};
  int duration = 2;
  EXPECT_EQ(3, solution_.findPoisonedDuration(timeSeries, duration));
}

TEST_P(TeemoAttackingTest, SelfAuthoredSingleAttack) {
  std::vector<int> timeSeries = {5};
  int duration = 3;
  EXPECT_EQ(3, solution_.findPoisonedDuration(timeSeries, duration));
}

TEST_P(TeemoAttackingTest, SelfAuthoredZeroDuration) {
  std::vector<int> timeSeries = {1, 2, 4};
  int duration = 0;
  EXPECT_EQ(0, solution_.findPoisonedDuration(timeSeries, duration));
}

TEST_P(TeemoAttackingTest, SelfAuthoredOverlappingChain) {
  std::vector<int> timeSeries = {1, 2, 3, 4, 5};
  int duration = 3;
  // Attacks at 1,2,3,4,5 each duration 3, always overlapping -> interval [1,7]
  EXPECT_EQ(7, solution_.findPoisonedDuration(timeSeries, duration));
}

INSTANTIATE_TEST_SUITE_P(
    TeemoAttackingTestSuite, TeemoAttackingTest,
    ::testing::ValuesIn(TeemoAttackingSolution().getStrategyNames()));

}  // namespace problem_495
}  // namespace leetcode
