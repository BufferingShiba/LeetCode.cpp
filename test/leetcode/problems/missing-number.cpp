#include "leetcode/problems/missing-number.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_268 {

class MissingNumberTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MissingNumberSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [3,0,1]
// Output: 2
TEST_P(MissingNumberTest, OfficialExample1) {
  vector<int> nums = {3, 0, 1};
  int result = solution.missingNumber(nums);
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [0,1]
// Output: 2
TEST_P(MissingNumberTest, OfficialExample2) {
  vector<int> nums = {0, 1};
  int result = solution.missingNumber(nums);
  EXPECT_EQ(2, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
TEST_P(MissingNumberTest, OfficialExample3) {
  vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  int result = solution.missingNumber(nums);
  EXPECT_EQ(8, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MissingNumberTest,
    ::testing::ValuesIn(MissingNumberSolution().getStrategyNames()));

}  // namespace problem_268
}  // namespace leetcode
