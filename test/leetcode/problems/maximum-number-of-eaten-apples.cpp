#include "leetcode/problems/maximum-number-of-eaten-apples.h"

#include "gtest/gtest.h"

#include <vector>

namespace leetcode {
namespace problem_1705 {

class MaximumNumberOfEatenApplesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfEatenApplesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  apples = [1,2,3,5,2], days = [3,2,1,4,2]
// Output: 7
TEST_P(MaximumNumberOfEatenApplesTest, OfficialExample1) {
  vector<int> apples = {1, 2, 3, 5, 2};
  vector<int> days = {3, 2, 1, 4, 2};
  EXPECT_EQ(7, solution.eatenApples(apples, days));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
// Output: 5
TEST_P(MaximumNumberOfEatenApplesTest, OfficialExample2) {
  vector<int> apples = {3, 0, 0, 0, 0, 2};
  vector<int> days = {3, 0, 0, 0, 0, 2};
  EXPECT_EQ(5, solution.eatenApples(apples, days));
}

// ===== Single day =====
// apples = [1], days = [1] -> eat 1 apple on day 1.
TEST_P(MaximumNumberOfEatenApplesTest, SingleDay) {
  vector<int> apples = {1};
  vector<int> days = {1};
  EXPECT_EQ(1, solution.eatenApples(apples, days));
}

// ===== No apples grow =====
// apples = [0,0,0], days = [0,0,0] -> nothing to eat.
TEST_P(MaximumNumberOfEatenApplesTest, NoApples) {
  vector<int> apples = {0, 0, 0};
  vector<int> days = {0, 0, 0};
  EXPECT_EQ(0, solution.eatenApples(apples, days));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumNumberOfEatenApplesTest,
    ::testing::ValuesIn(MaximumNumberOfEatenApplesSolution().getStrategyNames()));

}  // namespace problem_1705
}  // namespace leetcode
