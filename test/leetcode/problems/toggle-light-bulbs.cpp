#include <gtest/gtest.h>
#include "leetcode/problems/toggle-light-bulbs.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3842 {
namespace {

class ToggleLightBulbsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ToggleLightBulbsSolution solution;
};

TEST_P(ToggleLightBulbsTest, Example1) {
  std::vector<int> bulbs = {10, 30, 20, 10};
  std::vector<int> expected = {20, 30};
  EXPECT_EQ(solution.toggleLightBulbs(bulbs), expected);
}

TEST_P(ToggleLightBulbsTest, Example2) {
  std::vector<int> bulbs = {100, 100};
  std::vector<int> expected = {};
  EXPECT_EQ(solution.toggleLightBulbs(bulbs), expected);
}

TEST_P(ToggleLightBulbsTest, SelfAuthoredSingleBulbOn) {
  std::vector<int> bulbs = {5};
  std::vector<int> expected = {5};
  EXPECT_EQ(solution.toggleLightBulbs(bulbs), expected);
}

TEST_P(ToggleLightBulbsTest, SelfAuthoredSingleBulbTwice) {
  std::vector<int> bulbs = {5, 5};
  std::vector<int> expected = {};
  EXPECT_EQ(solution.toggleLightBulbs(bulbs), expected);
}

TEST_P(ToggleLightBulbsTest, SelfAuthoredMultipleOutOfOrder) {
  std::vector<int> bulbs = {3, 1, 2, 3};
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.toggleLightBulbs(bulbs), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ToggleLightBulbsTestSuite, ToggleLightBulbsTest,
    ::testing::ValuesIn(ToggleLightBulbsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3842
}  // namespace leetcode
