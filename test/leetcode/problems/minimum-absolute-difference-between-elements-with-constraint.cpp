#include "leetcode/problems/minimum-absolute-difference-between-elements-with-constraint.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2817 {

class MinimumAbsoluteDifferenceBetweenElementsWithConstraintTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [4,3,2,4], x = 2
// Output: 0
TEST_P(MinimumAbsoluteDifferenceBetweenElementsWithConstraintTest, OfficialExample1) {
  std::vector<int> nums = {4, 3, 2, 4};
  int x = 2;
  EXPECT_EQ(0, solution.minAbsoluteDifference(nums, x));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [5,3,2,10,15], x = 1
// Output: 1
TEST_P(MinimumAbsoluteDifferenceBetweenElementsWithConstraintTest, OfficialExample2) {
  std::vector<int> nums = {5, 3, 2, 10, 15};
  int x = 1;
  EXPECT_EQ(1, solution.minAbsoluteDifference(nums, x));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1,2,3,4], x = 3
// Output: 3
TEST_P(MinimumAbsoluteDifferenceBetweenElementsWithConstraintTest, OfficialExample3) {
  std::vector<int> nums = {1, 2, 3, 4};
  int x = 3;
  EXPECT_EQ(3, solution.minAbsoluteDifference(nums, x));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumAbsoluteDifferenceBetweenElementsWithConstraintTest,
    ::testing::ValuesIn(MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution().getStrategyNames()));

}  // namespace problem_2817
}  // namespace leetcode
