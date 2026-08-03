#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-number-of-special-subsequences.h"

namespace leetcode {
namespace problem_1955 {
namespace {

class CountNumberOfSpecialSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNumberOfSpecialSubsequencesSolution solution;
};

TEST_P(CountNumberOfSpecialSubsequencesTest, Example1) {
  std::vector<int> nums = {0, 1, 2, 2};
  EXPECT_EQ(3, solution.countSpecialSubsequences(nums));
}

TEST_P(CountNumberOfSpecialSubsequencesTest, Example2) {
  std::vector<int> nums = {2, 2, 0, 0};
  EXPECT_EQ(0, solution.countSpecialSubsequences(nums));
}

TEST_P(CountNumberOfSpecialSubsequencesTest, Example3) {
  std::vector<int> nums = {0, 1, 2, 0, 1, 2};
  EXPECT_EQ(7, solution.countSpecialSubsequences(nums));
}

TEST_P(CountNumberOfSpecialSubsequencesTest, SelfAuthoredSingleMinimal) {
  std::vector<int> nums = {0, 1, 2};
  EXPECT_EQ(1, solution.countSpecialSubsequences(nums));
}

TEST_P(CountNumberOfSpecialSubsequencesTest, SelfAuthoredNoTwos) {
  std::vector<int> nums = {0, 0, 1, 1};
  EXPECT_EQ(0, solution.countSpecialSubsequences(nums));
}

TEST_P(CountNumberOfSpecialSubsequencesTest, SelfAuthoredNoOnes) {
  std::vector<int> nums = {0, 0, 2, 2};
  EXPECT_EQ(0, solution.countSpecialSubsequences(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountNumberOfSpecialSubsequencesTestSuite,
    CountNumberOfSpecialSubsequencesTest,
    ::testing::ValuesIn(
        CountNumberOfSpecialSubsequencesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1955
}  // namespace leetcode
