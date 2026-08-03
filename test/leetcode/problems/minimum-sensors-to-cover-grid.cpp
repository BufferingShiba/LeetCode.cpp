#include "leetcode/problems/minimum-sensors-to-cover-grid.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3648 {

class MinimumSensorsToCoverGridTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSensorsToCoverGridSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 5, m = 5, k = 1
// Output: 4
TEST_P(MinimumSensorsToCoverGridTest, OfficialExample1) {
  int result1 = solution.minSensors(5, 5, 1);
  EXPECT_EQ(4, result1);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 2, m = 2, k = 2
// Output: 1
TEST_P(MinimumSensorsToCoverGridTest, OfficialExample2) {
  int result2 = solution.minSensors(2, 2, 2);
  EXPECT_EQ(1, result2);
}

// ===== Edge: k = 0 => each sensor covers a single cell =====
TEST_P(MinimumSensorsToCoverGridTest, ZeroRange) {
  EXPECT_EQ(6, solution.minSensors(2, 3, 0));
}

// ===== Edge: single cell always needs 1 sensor =====
TEST_P(MinimumSensorsToCoverGridTest, SingleCell) {
  EXPECT_EQ(1, solution.minSensors(1, 1, 1000));
  EXPECT_EQ(1, solution.minSensors(1, 1, 0));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumSensorsToCoverGridTest,
    ::testing::ValuesIn(MinimumSensorsToCoverGridSolution().getStrategyNames()));

}  // namespace problem_3648
}  // namespace leetcode
