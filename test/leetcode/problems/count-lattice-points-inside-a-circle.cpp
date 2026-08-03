#include <gtest/gtest.h>

#include "leetcode/problems/count-lattice-points-inside-a-circle.h"

namespace leetcode::problem_2249 {

class CountLatticePointsInsideACircleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountLatticePointsInsideACircleSolution solution_;
};

TEST_P(CountLatticePointsInsideACircleTest, Example1) {
  std::vector<std::vector<int>> circles = {{2, 2, 1}};
  EXPECT_EQ(solution_.countLatticePoints(circles), 5);
}

TEST_P(CountLatticePointsInsideACircleTest, Example2) {
  std::vector<std::vector<int>> circles = {{2, 2, 2}, {3, 4, 1}};
  EXPECT_EQ(solution_.countLatticePoints(circles), 16);
}

TEST_P(CountLatticePointsInsideACircleTest, SelfAuthoredOverlappingCircles) {
  // (1,1,r=1) has 5 points; (1,3,r=1) has 5 points; they share (1,2) → 9 distinct
  std::vector<std::vector<int>> circles = {{1, 1, 1}, {1, 3, 1}};
  EXPECT_EQ(solution_.countLatticePoints(circles), 9);
}

INSTANTIATE_TEST_SUITE_P(CountLatticePointsInsideACircle,
                         CountLatticePointsInsideACircleTest,
                         ::testing::ValuesIn(CountLatticePointsInsideACircleSolution()
                                                 .getStrategyNames()));

}  // namespace leetcode::problem_2249
