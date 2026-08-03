#include "leetcode/problems/minimum-index-of-a-valid-split.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2780 {

class MinimumIndexOfAValidSplitTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumIndexOfAValidSplitSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,2,2]
// Output: 2
TEST_P(MinimumIndexOfAValidSplitTest, OfficialExample1) {
  std::vector<int> nums = {1, 2, 2, 2};
  EXPECT_EQ(2, solution.minimumIndex(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [2,1,3,1,1,1,7,1,2,1]
// Output: 4
TEST_P(MinimumIndexOfAValidSplitTest, OfficialExample2) {
  std::vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
  EXPECT_EQ(4, solution.minimumIndex(nums));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [3,3,3,3,7,2,2]
// Output: -1
TEST_P(MinimumIndexOfAValidSplitTest, OfficialExample3) {
  std::vector<int> nums = {3, 3, 3, 3, 7, 2, 2};
  EXPECT_EQ(-1, solution.minimumIndex(nums));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumIndexOfAValidSplitTest,
    ::testing::ValuesIn(MinimumIndexOfAValidSplitSolution().getStrategyNames()));

}  // namespace problem_2780
}  // namespace leetcode
