#include "leetcode/problems/count-tested-devices-after-test-operations.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2960 {

class CountTestedDevicesAfterTestOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountTestedDevicesAfterTestOperationsSolution solution;
};

TEST_P(CountTestedDevicesAfterTestOperationsTest, Example1) {
  std::vector<int> batteryPercentages = {1, 1, 2, 1, 3};
  EXPECT_EQ(3, solution.countTestedDevices(batteryPercentages));
}

TEST_P(CountTestedDevicesAfterTestOperationsTest, Example2) {
  std::vector<int> batteryPercentages = {0, 1, 2};
  EXPECT_EQ(2, solution.countTestedDevices(batteryPercentages));
}

TEST_P(CountTestedDevicesAfterTestOperationsTest, SelfAuthoredSingleDeviceZero) {
  std::vector<int> batteryPercentages = {0};
  EXPECT_EQ(0, solution.countTestedDevices(batteryPercentages));
}

TEST_P(CountTestedDevicesAfterTestOperationsTest, SelfAuthoredSingleDevicePositive) {
  std::vector<int> batteryPercentages = {5};
  EXPECT_EQ(1, solution.countTestedDevices(batteryPercentages));
}

INSTANTIATE_TEST_SUITE_P(
    CountTestedDevicesAfterTestOperationsTestSuite,
    CountTestedDevicesAfterTestOperationsTest,
    ::testing::ValuesIn(
        CountTestedDevicesAfterTestOperationsSolution().getStrategyNames()));

}  // namespace problem_2960
}  // namespace leetcode
