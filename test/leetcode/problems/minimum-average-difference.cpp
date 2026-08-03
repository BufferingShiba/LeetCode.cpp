#include "leetcode/problems/minimum-average-difference.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2256 {
namespace {

class MinimumAverageDifferenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumAverageDifferenceSolution solution_;
};

TEST_P(MinimumAverageDifferenceTest, Example1) {
  std::vector<int> nums = {2, 5, 3, 9, 5, 3};
  EXPECT_EQ(solution_.minimumAverageDifference(nums), 3);
}

TEST_P(MinimumAverageDifferenceTest, Example2) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution_.minimumAverageDifference(nums), 0);
}

TEST_P(MinimumAverageDifferenceTest, AllEqual) {
  std::vector<int> nums = {1, 1, 1, 1};
  // Each index: left avg = 1, right avg = 1 or 0; smallest diff = 0 at idx 0.
  EXPECT_EQ(solution_.minimumAverageDifference(nums), 0);
}

TEST_P(MinimumAverageDifferenceTest, IncreasingTiny) {
  std::vector<int> nums = {1, 2, 3};
  // i=0: |1 - (2+3)/2| = |1-2| = 1, i=1: |(1+2)/2 - 3| = |1-3| = 2,
  // i=2: |(1+2+3)/3 - 0| = 2. Smallest index (diff=1) is 0.
  EXPECT_EQ(solution_.minimumAverageDifference(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAverageDifferenceStrategies, MinimumAverageDifferenceTest,
    ::testing::ValuesIn(MinimumAverageDifferenceSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2256
}  // namespace leetcode
