#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/minimum-time-difference.h"

namespace leetcode {
namespace problem_539 {
namespace {

class MinimumTimeDifferenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumTimeDifferenceSolution solution_;
};

TEST_P(MinimumTimeDifferenceTest, Example1) {
  std::vector<std::string> timePoints = {"23:59", "00:00"};
  EXPECT_EQ(1, solution_.findMinDifference(timePoints));
}

TEST_P(MinimumTimeDifferenceTest, Example2) {
  std::vector<std::string> timePoints = {"00:00", "23:59", "00:00"};
  EXPECT_EQ(0, solution_.findMinDifference(timePoints));
}

TEST_P(MinimumTimeDifferenceTest, ThreeTimes) {
  std::vector<std::string> timePoints = {"12:00", "00:30", "23:30"};
  // Sorted minutes: 30, 720, 1410. Adjacent diffs: 690, 690. Wrap-around:
  // 30 + 1440 - 1410 = 60.
  EXPECT_EQ(60, solution_.findMinDifference(timePoints));
}

TEST_P(MinimumTimeDifferenceTest, AcrossMidnight) {
  std::vector<std::string> timePoints = {"23:30", "00:10", "12:00"};
  // Sorted minutes: 10, 720, 1410. Adjacent: 710, 690. Wrap-around:
  // 10 + 1440 - 1410 = 40.
  EXPECT_EQ(40, solution_.findMinDifference(timePoints));
}

TEST_P(MinimumTimeDifferenceTest, AdjacentTimes) {
  std::vector<std::string> timePoints = {"10:30", "10:31", "09:00"};
  // Sorted minutes: 540, 630, 631. Adjacent: 90, 1. Wrap-around:
  // 540 + 1440 - 631 = 1349. Min = 1.
  EXPECT_EQ(1, solution_.findMinDifference(timePoints));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumTimeDifferenceTestSuite, MinimumTimeDifferenceTest,
    ::testing::ValuesIn(MinimumTimeDifferenceSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_539
}  // namespace leetcode
