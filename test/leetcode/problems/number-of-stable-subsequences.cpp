#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-stable-subsequences.h"

namespace leetcode {
namespace problem_3686 {

class NumberOfStableSubsequencesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfStableSubsequencesSolution solution_;
};

TEST_P(NumberOfStableSubsequencesTest, Example1) {
  std::vector<int> nums = {1, 3, 5};
  EXPECT_EQ(6, solution_.countStableSubsequences(nums));
}

TEST_P(NumberOfStableSubsequencesTest, Example2) {
  std::vector<int> nums = {2, 3, 4, 2};
  EXPECT_EQ(14, solution_.countStableSubsequences(nums));
}

TEST_P(NumberOfStableSubsequencesTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(1, solution_.countStableSubsequences(nums));
}

TEST_P(NumberOfStableSubsequencesTest, SelfAuthoredTwoSameParity) {
  std::vector<int> nums = {2, 4};
  // Subsequences: [2], [4], [2,4] -> all stable.
  EXPECT_EQ(3, solution_.countStableSubsequences(nums));
}

TEST_P(NumberOfStableSubsequencesTest, SelfAuthoredThreeSameParity) {
  std::vector<int> nums = {1, 1, 1};
  // All non-empty subsequences are stable except the full triple {1,1,1}. count = 2^3 - 2 = 6.
  EXPECT_EQ(6, solution_.countStableSubsequences(nums));
}

TEST_P(NumberOfStableSubsequencesTest, SelfAuthoredFourSameParity) {
  std::vector<int> nums = {2, 2, 2, 2};
  // All subsequences containing three consecutive equal-parity elems are the ones of size>=3.
  // Total non-empty = 15. Unstable: subsequences of length 3 (choose {any 3 of 4} = 4) and length 4 (1).
  // But overlapping: enumerate subsequences by positions. Length-3 subsequences: {0,1,2},{0,1,3},{0,2,3},{1,2,3} all have 3 consecutive evens -> unstable. Length 4 -> unstable.
  // Stable: all singletons(4) and pairs(6) -> 10.
  EXPECT_EQ(10, solution_.countStableSubsequences(nums));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfStableSubsequencesTestCases,
    NumberOfStableSubsequencesTest,
    ::testing::ValuesIn(NumberOfStableSubsequencesSolution().getStrategyNames()));

}  // namespace problem_3686
}  // namespace leetcode
