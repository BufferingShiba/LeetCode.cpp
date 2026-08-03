#include "leetcode/problems/number-of-perfect-pairs.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3649 {

class NumberOfPerfectPairsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfPerfectPairsSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NumberOfPerfectPairsTest,
    ::testing::ValuesIn(NumberOfPerfectPairsSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [0,1,2,3]
// Output: 2
TEST_P(NumberOfPerfectPairsTest, OfficialExample1) {
  std::vector<int> nums = {0, 1, 2, 3};
  long result = solution.perfectPairs(nums);
  EXPECT_EQ(2L, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [-3,2,-1,4]
// Output: 4
TEST_P(NumberOfPerfectPairsTest, OfficialExample2) {
  std::vector<int> nums = {-3, 2, -1, 4};
  long result = solution.perfectPairs(nums);
  EXPECT_EQ(4L, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1,10,100,1000]
// Output: 0
TEST_P(NumberOfPerfectPairsTest, OfficialExample3) {
  std::vector<int> nums = {1, 10, 100, 1000};
  long result = solution.perfectPairs(nums);
  EXPECT_EQ(0L, result);
}

// ===== Self-authored: both zeros -> perfect, zero with nonzero -> not =====
// Input:  nums = [0,0,5]
// Pairs: (0,0) perfect (0==0<=0), (0,5) -> max=5,2*min=0 -> not,
//        (0,5) similarly not. So answer = 1.
TEST_P(NumberOfPerfectPairsTest, ZeroNonZero) {
  std::vector<int> nums = {0, 0, 5};
  long result = solution.perfectPairs(nums);
  EXPECT_EQ(1L, result);
}

// ===== Self-authored: equal absolute values are always perfect =====
// Input:  nums = [-2, 2]
// max=2 <= 2*min=4 -> perfect. Answer = 1.
TEST_P(NumberOfPerfectPairsTest, EqualAbsCrossSign) {
  std::vector<int> nums = {-2, 2};
  long result = solution.perfectPairs(nums);
  EXPECT_EQ(1L, result);
}

}  // namespace problem_3649
}  // namespace leetcode
