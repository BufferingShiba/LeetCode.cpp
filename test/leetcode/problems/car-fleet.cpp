#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/car-fleet.h"

namespace leetcode {
namespace problem_853 {

class CarFleetTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CarFleetSolution solution_;
};

TEST_P(CarFleetTest, Example1) {
  int target = 12;
  std::vector<int> position = {10, 8, 0, 5, 3};
  std::vector<int> speed = {2, 4, 1, 1, 3};
  EXPECT_EQ(solution_.carFleet(target, position, speed), 3);
}

TEST_P(CarFleetTest, Example2) {
  int target = 10;
  std::vector<int> position = {3};
  std::vector<int> speed = {3};
  EXPECT_EQ(solution_.carFleet(target, position, speed), 1);
}

TEST_P(CarFleetTest, Example3) {
  int target = 100;
  std::vector<int> position = {0, 2, 4};
  std::vector<int> speed = {4, 2, 1};
  EXPECT_EQ(solution_.carFleet(target, position, speed), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CarFleetTest,
                         ::testing::ValuesIn(
                             CarFleetSolution().getStrategyNames()));

}  // namespace problem_853
}  // namespace leetcode
