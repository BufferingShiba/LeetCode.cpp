#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/magnetic-force-between-two-balls.h"

namespace leetcode {
namespace problem_1552 {
namespace {

using TestingParam = std::string;

class MagneticForceBetweenTwoBallsTest
    : public testing::TestWithParam<TestingParam> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MagneticForceBetweenTwoBallsSolution solution;
};

TEST_P(MagneticForceBetweenTwoBallsTest, Example1) {
  std::vector<int> position = {1, 2, 3, 4, 7};
  int m = 3;
  EXPECT_EQ(solution.maxDistance(position, m), 3);
}

TEST_P(MagneticForceBetweenTwoBallsTest, Example2) {
  std::vector<int> position = {5, 4, 3, 2, 1, 1000000000};
  int m = 2;
  EXPECT_EQ(solution.maxDistance(position, m), 999999999);
}

TEST_P(MagneticForceBetweenTwoBallsTest, SelfAuthored_MinimalCase) {
  std::vector<int> position = {1, 10};
  int m = 2;
  EXPECT_EQ(solution.maxDistance(position, m), 9);
}

TEST_P(MagneticForceBetweenTwoBallsTest, SelfAuthored_AllBasketsUsed) {
  std::vector<int> position = {1, 2, 3, 4};
  int m = 4;
  EXPECT_EQ(solution.maxDistance(position, m), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MagneticForceBetweenTwoBallsTest,
    testing::ValuesIn(
        MagneticForceBetweenTwoBallsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1552
}  // namespace leetcode
