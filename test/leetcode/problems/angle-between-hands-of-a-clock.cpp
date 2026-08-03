#include <gtest/gtest.h>

#include <cmath>

#include "leetcode/problems/angle-between-hands-of-a-clock.h"

namespace leetcode {
namespace problem_1344 {

class AngleBetweenHandsOfAClockTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AngleBetweenHandsOfAClockSolution solution;
};

TEST_P(AngleBetweenHandsOfAClockTest, Example1) {
  double result = solution.angleClock(12, 30);
  EXPECT_NEAR(result, 165.0, 1e-5);
}

TEST_P(AngleBetweenHandsOfAClockTest, Example2) {
  double result = solution.angleClock(3, 30);
  EXPECT_NEAR(result, 75.0, 1e-5);
}

TEST_P(AngleBetweenHandsOfAClockTest, Example3) {
  double result = solution.angleClock(3, 15);
  EXPECT_NEAR(result, 7.5, 1e-5);
}

TEST_P(AngleBetweenHandsOfAClockTest, SelfAuthoredExactNoon) {
  // 12:00 → both hands at 0°
  double result = solution.angleClock(12, 0);
  EXPECT_NEAR(result, 0.0, 1e-5);
}

TEST_P(AngleBetweenHandsOfAClockTest, SelfAuthoredSixOClock) {
  // 6:00 → hour at 180°, minute at 0°, diff = 180°
  double result = solution.angleClock(6, 0);
  EXPECT_NEAR(result, 180.0, 1e-5);
}

TEST_P(AngleBetweenHandsOfAClockTest, SelfAuthoredOpposite) {
  // 9:00 → hour at 270°, minute at 0°, smaller = 90°
  double result = solution.angleClock(9, 0);
  EXPECT_NEAR(result, 90.0, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(Strategies, AngleBetweenHandsOfAClockTest,
                         testing::ValuesIn(AngleBetweenHandsOfAClockSolution()
                                               .getStrategyNames()));

}  // namespace problem_1344
}  // namespace leetcode
