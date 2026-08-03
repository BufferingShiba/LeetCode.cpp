#include "leetcode/problems/count-number-of-ways-to-place-houses.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2320 {

class CountNumberOfWaysToPlaceHousesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNumberOfWaysToPlaceHousesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 1
// Output: 4
TEST_P(CountNumberOfWaysToPlaceHousesTest, OfficialExample1) {
  int result = solution.countHousePlacements(1);
  EXPECT_EQ(4, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 2
// Output: 9
TEST_P(CountNumberOfWaysToPlaceHousesTest, OfficialExample2) {
  int result = solution.countHousePlacements(2);
  EXPECT_EQ(9, result);
}

// ===== Boundary: n = 3 =====
// f(3) = f(2)+f(1) = 3+2 = 5, answer = 25
TEST_P(CountNumberOfWaysToPlaceHousesTest, BoundaryN3) {
  int result = solution.countHousePlacements(3);
  EXPECT_EQ(25, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountNumberOfWaysToPlaceHousesTest,
    ::testing::ValuesIn(CountNumberOfWaysToPlaceHousesSolution().getStrategyNames()));

}  // namespace problem_2320
}  // namespace leetcode
