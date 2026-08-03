#include "leetcode/problems/non-decreasing-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_665 {

class NonDecreasingArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NonDecreasingArraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [4,2,3]
// Output: true
TEST_P(NonDecreasingArrayTest, OfficialExample1) {
  vector<int> nums = {4, 2, 3};
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [4,2,1]
// Output: false
TEST_P(NonDecreasingArrayTest, OfficialExample2) {
  vector<int> nums = {4, 2, 1};
  EXPECT_EQ(false, solution.checkPossibility(nums));
}

// ===== Self-verified edge cases =====
TEST_P(NonDecreasingArrayTest, SingleElement) {
  vector<int> nums = {1};
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, AlreadyNonDecreasing) {
  vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, TwoDecreasingPairs) {
  vector<int> nums = {3, 2, 4, 1};
  EXPECT_EQ(false, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, LowerFirstElementWorks) {
  vector<int> nums = {5, 7, 1, 8};
  // Modify 7 -> 1 gives [5,1,1,8]? No: violation at index 1 (7 > 1).
  // nums[0]=5 <= nums[2]=1 is false, so raise nums[2]=1 -> 7 -> [5,7,7,8].
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, RaiseToFixGap) {
  vector<int> nums = {-1, 4, 2, 3};
  // Violation at i=1 (4 > 2). nums[0]=-1 <= nums[2]=2, lower 4 -> 2 => [-1,2,2,3].
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, FixDuplicateRun) {
  vector<int> nums = {1, 2, 5, 2, 3};
  // Violation at i=2 (5 > 2). nums[1]=2 <= nums[3]=2, lower 5 -> 2 => [1,2,2,2,3].
  EXPECT_EQ(true, solution.checkPossibility(nums));
}

TEST_P(NonDecreasingArrayTest, CannotFixEasy) {
  vector<int> nums = {3, 2, 1, 4};
  // Violations: i=0 (3>2), i=1 (2>1). More than one dip impossible.
  // Actually first fix at i=0 lowers 3->2 => [2,2,1,4], then i=2 (1>... no, 2>1 at i=1)
  // [2,2,1,4]: violation at i=1 (2>1) -> second modification => false.
  EXPECT_EQ(false, solution.checkPossibility(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NonDecreasingArrayTest,
    ::testing::ValuesIn(NonDecreasingArraySolution().getStrategyNames()));

}  // namespace problem_665
}  // namespace leetcode
