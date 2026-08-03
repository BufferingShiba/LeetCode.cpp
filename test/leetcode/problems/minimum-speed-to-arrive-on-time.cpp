#include "leetcode/problems/minimum-speed-to-arrive-on-time.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1870 {

class MinimumSpeedToArriveOnTimeTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSpeedToArriveOnTimeSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  dist = [1,3,2], hour = 6
// Output: 1
TEST_P(MinimumSpeedToArriveOnTimeTest, OfficialExample1) {
  std::vector<int> dist = {1, 3, 2};
  EXPECT_EQ(1, solution.minSpeedOnTime(dist, 6));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  dist = [1,3,2], hour = 2.7
// Output: 3
TEST_P(MinimumSpeedToArriveOnTimeTest, OfficialExample2) {
  std::vector<int> dist = {1, 3, 2};
  EXPECT_EQ(3, solution.minSpeedOnTime(dist, 2.7));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  dist = [1,3,2], hour = 1.9
// Output: -1
TEST_P(MinimumSpeedToArriveOnTimeTest, OfficialExample3) {
  std::vector<int> dist = {1, 3, 2};
  EXPECT_EQ(-1, solution.minSpeedOnTime(dist, 1.9));
}

// ===== SelfAuthored edge case (single train) =====
// Input:  dist = [1], hour = 1
// Output: 1  (ride takes 1/1 = 1 hour)
TEST_P(MinimumSpeedToArriveOnTimeTest, SelfAuthoredSingleTrain) {
  std::vector<int> dist = {1};
  EXPECT_EQ(1, solution.minSpeedOnTime(dist, 1));
}

// ===== SelfAuthored edge case (last train can use fractional hour) =====
// Input:  dist = [1], hour = 1.5
// Output: 1  (ride 1/1 = 1 <= 1.5)
TEST_P(MinimumSpeedToArriveOnTimeTest, SelfAuthoredLastTrainFractional) {
  std::vector<int> dist = {1};
  EXPECT_EQ(1, solution.minSpeedOnTime(dist, 1.5));
}

// ===== SelfAuthored edge case (need large speed for last fractional) =====
// Input:  dist = [1], hour = 0.5
// Output: 2  (1/s <= 0.5 -> s >= 2)
TEST_P(MinimumSpeedToArriveOnTimeTest, SelfAuthoredFractionalNeedSpeed2) {
  std::vector<int> dist = {1};
  EXPECT_EQ(2, solution.minSpeedOnTime(dist, 0.5));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumSpeedToArriveOnTimeTest,
    ::testing::ValuesIn(MinimumSpeedToArriveOnTimeSolution().getStrategyNames()));

}  // namespace problem_1870
}  // namespace leetcode
