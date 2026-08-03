#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/distance-between-bus-stops.h"

namespace leetcode::problem_1184 {

class DistanceBetweenBusStopsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistanceBetweenBusStopsSolution solution;
};

TEST_P(DistanceBetweenBusStopsTest, Example1) {
  std::vector<int> distance{1, 2, 3, 4};
  EXPECT_EQ(solution.distanceBetweenBusStops(distance, 0, 1), 1);
}

TEST_P(DistanceBetweenBusStopsTest, Example2) {
  std::vector<int> distance{1, 2, 3, 4};
  EXPECT_EQ(solution.distanceBetweenBusStops(distance, 0, 2), 3);
}

TEST_P(DistanceBetweenBusStopsTest, Example3) {
  std::vector<int> distance{1, 2, 3, 4};
  EXPECT_EQ(solution.distanceBetweenBusStops(distance, 0, 3), 4);
}

TEST_P(DistanceBetweenBusStopsTest, ReverseDirection) {
  std::vector<int> distance{1, 2, 3, 4};
  // total = 10; start=3, dest=1. Swap -> start=1,dest=3.
  // clockwise 1->3 = distance[1]+distance[2] = 2+3 = 5; other = 5. answer 5.
  EXPECT_EQ(solution.distanceBetweenBusStops(distance, 3, 1), 5);
}

TEST_P(DistanceBetweenBusStopsTest, SameStop) {
  std::vector<int> distance{7, 10, 21, 30};
  EXPECT_EQ(solution.distanceBetweenBusStops(distance, 2, 2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    DistanceBetweenBusStopsTestSuite, DistanceBetweenBusStopsTest,
    ::testing::ValuesIn(DistanceBetweenBusStopsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1184
