#include "leetcode/problems/find-the-kth-largest-integer-in-the-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1985 {

class FindTheKthLargestIntegerInTheArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheKthLargestIntegerInTheArraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = ["3","6","7","10"], k = 4
// Output: "3"
TEST_P(FindTheKthLargestIntegerInTheArrayTest, OfficialExample1) {
  vector<string> nums = {"3", "6", "7", "10"};
  string result = solution.kthLargestNumber(nums, 4);
  EXPECT_EQ("3", result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = ["2","21","12","1"], k = 3
// Output: "2"
TEST_P(FindTheKthLargestIntegerInTheArrayTest, OfficialExample2) {
  vector<string> nums = {"2", "21", "12", "1"};
  string result = solution.kthLargestNumber(nums, 3);
  EXPECT_EQ("2", result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = ["0","0"], k = 2
// Output: "0"
TEST_P(FindTheKthLargestIntegerInTheArrayTest, OfficialExample3) {
  vector<string> nums = {"0", "0"};
  string result = solution.kthLargestNumber(nums, 2);
  EXPECT_EQ("0", result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheKthLargestIntegerInTheArrayTest,
    ::testing::ValuesIn(FindTheKthLargestIntegerInTheArraySolution().getStrategyNames()));

}  // namespace problem_1985
}  // namespace leetcode
