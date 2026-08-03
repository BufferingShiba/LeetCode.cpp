#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/points-that-intersect-with-cars.h"

namespace leetcode {
namespace problem_2848 {

class PointsThatIntersectWithCarsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PointsThatIntersectWithCarsSolution solution_;
};

TEST_P(PointsThatIntersectWithCarsTest, Example1) {
  std::vector<std::vector<int>> nums = {{3, 6}, {1, 5}, {4, 7}};
  EXPECT_EQ(solution_.numberOfPoints(nums), 7);
}

TEST_P(PointsThatIntersectWithCarsTest, Example2) {
  std::vector<std::vector<int>> nums = {{1, 3}, {5, 8}};
  EXPECT_EQ(solution_.numberOfPoints(nums), 7);
}

TEST_P(PointsThatIntersectWithCarsTest, SelfAuthoredSingleInterval) {
  std::vector<std::vector<int>> nums = {{5, 5}};
  EXPECT_EQ(solution_.numberOfPoints(nums), 1);
}

TEST_P(PointsThatIntersectWithCarsTest, SelfAuthoredMaxRange) {
  std::vector<std::vector<int>> nums = {{1, 100}};
  EXPECT_EQ(solution_.numberOfPoints(nums), 100);
}

INSTANTIATE_TEST_SUITE_P(
    PointsThatIntersectWithCarsTestSuite, PointsThatIntersectWithCarsTest,
    ::testing::ValuesIn(
        PointsThatIntersectWithCarsSolution().getStrategyNames()));

}  // namespace problem_2848
}  // namespace leetcode
