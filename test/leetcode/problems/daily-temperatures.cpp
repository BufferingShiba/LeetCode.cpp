#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/daily-temperatures.h"

namespace leetcode {
namespace problem_739 {

class DailyTemperaturesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DailyTemperaturesSolution solution_;
};

TEST_P(DailyTemperaturesTest, Example1) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

TEST_P(DailyTemperaturesTest, Example2) {
  std::vector<int> temperatures = {30, 40, 50, 60};
  std::vector<int> expected = {1, 1, 1, 0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

TEST_P(DailyTemperaturesTest, Example3) {
  std::vector<int> temperatures = {30, 60, 90};
  std::vector<int> expected = {1, 1, 0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

TEST_P(DailyTemperaturesTest, SelfAuthoredSingleElement) {
  std::vector<int> temperatures = {50};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

TEST_P(DailyTemperaturesTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> temperatures = {90, 80, 70, 60};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

TEST_P(DailyTemperaturesTest, SelfAuthoredEqualTemperatures) {
  std::vector<int> temperatures = {50, 50, 50};
  std::vector<int> expected = {0, 0, 0};
  EXPECT_EQ(solution_.dailyTemperatures(temperatures), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DailyTemperaturesTest,
    ::testing::ValuesIn(DailyTemperaturesSolution().getStrategyNames()));

}  // namespace problem_739
}  // namespace leetcode
