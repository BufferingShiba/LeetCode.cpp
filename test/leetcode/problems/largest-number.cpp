#include "leetcode/problems/largest-number.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_179 {

class LargestNumberTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestNumberSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [10,2]
// Output: "210"
TEST_P(LargestNumberTest, OfficialExample1) {
  vector<int> nums = {10, 2};
  EXPECT_EQ("210", solution.largestNumber(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [3,30,34,5,9]
// Output: "9534330"
TEST_P(LargestNumberTest, OfficialExample2) {
  vector<int> nums = {3, 30, 34, 5, 9};
  EXPECT_EQ("9534330", solution.largestNumber(nums));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1]
// Output: "1"
TEST_P(LargestNumberTest, OfficialExample3) {
  vector<int> nums = {1};
  EXPECT_EQ("1", solution.largestNumber(nums));
}

// ===== Official Example 4 (from LeetCode) =====
// Input:  nums = [0,0]
// Output: "0"
TEST_P(LargestNumberTest, OfficialExample4) {
  vector<int> nums = {0, 0};
  EXPECT_EQ("0", solution.largestNumber(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, LargestNumberTest,
    ::testing::ValuesIn(LargestNumberSolution().getStrategyNames()));

}  // namespace problem_179
}  // namespace leetcode
