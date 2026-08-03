#include "leetcode/problems/minimum-time-to-complete-trips.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2187 {

class MinimumTimeToCompleteTripsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumTimeToCompleteTripsSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumTimeToCompleteTripsTest,
    ::testing::ValuesIn(MinimumTimeToCompleteTripsSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  time = [1,2,3], totalTrips = 5
// Output: 3
TEST_P(MinimumTimeToCompleteTripsTest, OfficialExample1) {
  std::vector<int> time = {1, 2, 3};
  int totalTrips = 5;
  long result = solution.minimumTime(time, totalTrips);
  EXPECT_EQ(3L, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  time = [2], totalTrips = 1
// Output: 2
TEST_P(MinimumTimeToCompleteTripsTest, OfficialExample2) {
  std::vector<int> time = {2};
  int totalTrips = 1;
  long result = solution.minimumTime(time, totalTrips);
  EXPECT_EQ(2L, result);
}

}  // namespace problem_2187
}  // namespace leetcode
