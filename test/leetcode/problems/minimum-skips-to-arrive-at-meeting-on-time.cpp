#include "leetcode/problems/minimum-skips-to-arrive-at-meeting-on-time.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using leetcode::problem_1883::MinimumSkipsToArriveAtMeetingOnTimeSolution;

namespace {

struct TestCase {
  std::vector<int> dist;
  int speed;
  int hoursBefore;
  int expected;
};

}  // namespace

class MinimumSkipsToArriveAtMeetingOnTimeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumSkipsToArriveAtMeetingOnTimeSolution solution_;
};

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, Example1) {
  std::vector<int> dist = {1, 3, 2};
  EXPECT_EQ(solution_.minSkips(dist, 4, 2), 1);
}

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, Example2) {
  std::vector<int> dist = {7, 3, 5, 5};
  EXPECT_EQ(solution_.minSkips(dist, 2, 10), 2);
}

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, Example3) {
  std::vector<int> dist = {7, 3, 5, 5};
  EXPECT_EQ(solution_.minSkips(dist, 1, 10), -1);
}

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, SingleRoad) {
  // Only one road, no rest needed.
  std::vector<int> dist = {10};
  EXPECT_EQ(solution_.minSkips(dist, 5, 2), 0);
}

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, NeedOneSkip) {
  // Each road 0.5h. Without skip: 0.5 -> wait to 1h -> 0.5 => 1.5h > 1h.
  // With 1 skip: 0.5 + 0.5 = 1h <= 1h.
  std::vector<int> dist = {1, 1};
  EXPECT_EQ(solution_.minSkips(dist, 2, 1), 1);
}

TEST_P(MinimumSkipsToArriveAtMeetingOnTimeTest, ImpossibleEvenSkippingAll) {
  // Each road 0.75h; skip all -> 1.5h > 1h, impossible.
  std::vector<int> dist = {3, 3};
  EXPECT_EQ(solution_.minSkips(dist, 4, 1), -1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSkipsToArriveAtMeetingOnTimeParams,
    MinimumSkipsToArriveAtMeetingOnTimeTest,
    ::testing::ValuesIn(
        MinimumSkipsToArriveAtMeetingOnTimeSolution().getStrategyNames()));
