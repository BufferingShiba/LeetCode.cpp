#include <cmath>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/car-fleet-ii.h"

namespace leetcode {
namespace problem_1776 {
namespace {

void AssertDoubleVectorApprox(const std::vector<double>& actual,
                              const std::vector<double>& expected,
                              double eps = 1e-5) {
  ASSERT_EQ(expected.size(), actual.size());
  for (std::size_t i = 0; i < expected.size(); ++i) {
    EXPECT_NEAR(expected[i], actual[i], eps) << "index: " << i;
  }
}

}  // namespace

class CarFleetIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CarFleetIiSolution solution;
};

TEST_P(CarFleetIiTest, Example1) {
  std::vector<std::vector<int>> cars = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};
  std::vector<double> expected = {1.0, -1.0, 3.0, -1.0};
  AssertDoubleVectorApprox(solution.getCollisionTimes(cars), expected);
}

TEST_P(CarFleetIiTest, Example2) {
  std::vector<std::vector<int>> cars = {{3, 4}, {5, 4}, {6, 3}, {9, 1}};
  std::vector<double> expected = {2.0, 1.0, 1.5, -1.0};
  AssertDoubleVectorApprox(solution.getCollisionTimes(cars), expected);
}

TEST_P(CarFleetIiTest, SelfAuthoredSingleCar) {
  std::vector<std::vector<int>> cars = {{5, 3}};
  std::vector<double> expected = {-1.0};
  AssertDoubleVectorApprox(solution.getCollisionTimes(cars), expected);
}

TEST_P(CarFleetIiTest, SelfAuthoredAllFasterInFront) {
  std::vector<std::vector<int>> cars = {{1, 1}, {2, 5}, {3, 10}};
  // Slower car in front: nothing gets caught.
  std::vector<double> expected = {-1.0, -1.0, -1.0};
  AssertDoubleVectorApprox(solution.getCollisionTimes(cars), expected);
}

TEST_P(CarFleetIiTest, SelfAuthoredChainCollision) {
  // Car0(0,4) catches Car1(5,1)? gap=5, rel=3 => 5/3. Car1(5,1) vs Car2 far ahead never.
  std::vector<std::vector<int>> cars = {{0, 4}, {5, 1}, {100, 10}};
  std::vector<double> expected = {5.0 / 3.0, -1.0, -1.0};
  AssertDoubleVectorApprox(solution.getCollisionTimes(cars), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CarFleetIiTestSuite, CarFleetIiTest,
    ::testing::ValuesIn(CarFleetIiSolution().getStrategyNames()));

}  // namespace problem_1776
}  // namespace leetcode
