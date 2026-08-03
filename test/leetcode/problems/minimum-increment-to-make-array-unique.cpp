#include "leetcode/problems/minimum-increment-to-make-array-unique.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_945 {

class MinimumIncrementToMakeArrayUniqueTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumIncrementToMakeArrayUniqueSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,2]
// Output: 1
TEST_P(MinimumIncrementToMakeArrayUniqueTest, OfficialExample1) {
  std::vector<int> nums = {1, 2, 2};
  EXPECT_EQ(1, solution.minIncrementForUnique(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [3,2,1,2,1,7]
// Output: 6
TEST_P(MinimumIncrementToMakeArrayUniqueTest, OfficialExample2) {
  std::vector<int> nums = {3, 2, 1, 2, 1, 7};
  EXPECT_EQ(6, solution.minIncrementForUnique(nums));
}

// ===== SelfAuthored Edge Case =====
// All unique already -> no moves needed.
TEST_P(MinimumIncrementToMakeArrayUniqueTest, AllUniqueNoMoves) {
  std::vector<int> nums = {0, 1, 3, 5};
  EXPECT_EQ(0, solution.minIncrementForUnique(nums));
}

// ===== SelfAuthored Edge Case =====
// Many duplicates at the same value.
TEST_P(MinimumIncrementToMakeArrayUniqueTest, ManyDuplicates) {
  std::vector<int> nums = {3, 3, 3, 3};
  // Sort: [3,3,3,3] -> [3,4,5,6], moves = 0+1+2+3 = 6
  EXPECT_EQ(6, solution.minIncrementForUnique(nums));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumIncrementToMakeArrayUniqueTest,
    ::testing::ValuesIn(MinimumIncrementToMakeArrayUniqueSolution().getStrategyNames()));

}  // namespace problem_945
}  // namespace leetcode
