#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/convert-the-temperature.h"

namespace leetcode::problem_2469 {

class ConvertTheTemperatureTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConvertTheTemperatureSolution solution;
};

TEST_P(ConvertTheTemperatureTest, Example1) {
  std::vector<double> ans = solution.convertTemperature(36.50);
  ASSERT_EQ(ans.size(), 2U);
  EXPECT_NEAR(ans[0], 309.65000, 1e-5);
  EXPECT_NEAR(ans[1], 97.70000, 1e-5);
}

TEST_P(ConvertTheTemperatureTest, Example2) {
  std::vector<double> ans = solution.convertTemperature(122.11);
  ASSERT_EQ(ans.size(), 2U);
  EXPECT_NEAR(ans[0], 395.26000, 1e-5);
  EXPECT_NEAR(ans[1], 251.79800, 1e-5);
}

TEST_P(ConvertTheTemperatureTest, SelfAuthoredZeroCelsius) {
  std::vector<double> ans = solution.convertTemperature(0.0);
  ASSERT_EQ(ans.size(), 2U);
  EXPECT_NEAR(ans[0], 273.15, 1e-5);
  EXPECT_NEAR(ans[1], 32.00, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    ConvertTheTemperatureTestSuite, ConvertTheTemperatureTest,
    ::testing::ValuesIn(ConvertTheTemperatureSolution().getStrategyNames()));

}  // namespace leetcode::problem_2469
